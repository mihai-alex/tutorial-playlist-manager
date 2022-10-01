#include "comparator.h"

bool ComparatorAscendingByLikes::compare(Tutorial a, Tutorial b) {
	return (a.getLikes() <= b.getLikes());
}

bool ComparatorDescendingByTitle::compare(Tutorial a, Tutorial b) {
	return (a.getTitle() >= b.getTitle());
}

void testComparatorSort() {
	std::vector<Tutorial> elems;

	std::string title = "";
	std::string presenter = "";
	int minutes = 0;
	int seconds = 0;
	int likes = 0;
	std::string link = "";

	std::string samples[11] = { "test0\0", "test1\0", "test2\0", "test3\0" , "test4\0" , "test5\0" ,
		"test6\0" , "test7\0" , "test8\0" , "test9\0" };

	std::string links[11] = { "https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q",
		"https://www.youtube.com/watch?v=UTWC74XRr7Q" };

	for (int i = 0; i < 10; i++) {
		title = samples[i];
		presenter = samples[i];
		minutes = i;
		seconds = i;
		likes = 10 - i;
		link = links[i];

		Pair d{ minutes, seconds };
		Tutorial t{ title, presenter, d, likes, link };
		elems.push_back(t);
	}

	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			assert(elems[i].getLikes() > elems[j].getLikes());
		}
	}

	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			assert(elems[i].getTitle() < elems[j].getTitle());
		}
	}

	ComparatorAscendingByLikes* comp1 = new ComparatorAscendingByLikes;
	ComparatorDescendingByTitle* comp2 = new ComparatorDescendingByTitle;

	genericSort(elems, comp1);
	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			assert(elems[i].getLikes() <= elems[j].getLikes());
		}
	}

	genericSort(elems, comp2);
	for (int i = 0; i < elems.size() - 1; i++) {
		for (int j = i + 1; j < elems.size(); j++) {
			assert(elems[i].getTitle() >= elems[j].getTitle());
		}
	}

	delete comp1;
	delete comp2;
}
