#pragma once
#include "domain.h"
#include <vector>
#include <algorithm>
#include <assert.h>

template<typename T>
class Comparator {
public:
	virtual bool compare(T a, T b) = 0;
};

class ComparatorAscendingByLikes : public Comparator<Tutorial> {
	bool compare(Tutorial a, Tutorial b) override;
};

class ComparatorDescendingByTitle : public Comparator<Tutorial> {
	bool compare(Tutorial a, Tutorial b) override;
};

template<typename T>
inline void genericSort(std::vector<T>& elems, Comparator<T>* comp) {
	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			if (!comp->compare(elems[i], elems[j])) {
				std::swap(elems[i], elems[j]);
			}
		}
	}
}

void testComparatorSort();