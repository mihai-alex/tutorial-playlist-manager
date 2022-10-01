#pragma once
#include "repository.h"
#include <algorithm>

class Controller {
private:
	Repository* repository;
	Repository* fileWatchlistRepository;

public:
	Controller();

	void allocWatchlistCSV();
	void allocWatchlistHTML();

	~Controller();

	void readTutorialsFromFile();
	void writeTutorialsToFile();

	void readWatchlistFromFile();
	void writeWatchlistToFile();

	void openFileExternal();

	// adds a turorial with the given properties to the list of tutorials
	// returns -1 if the tutorial already exists, 1 otherwise (was successfuly added)
	void addTutorial(std::string title, std::string presenter,
		int minutes, int seconds, int likes, std::string link);

	void addTutorialObject(const Tutorial& tutorial);

	// adds a turorial with the given properties to the watch list
	// returns -1 if the tutorial already exists, 1 otherwise (was successfuly added)
	void addTutorialToWatchList(const Tutorial& tutorial);

	// updates a turorial with a given title and the given properties in the tutorial list
	// returns -1 if the tutorial does not exist, 1 otherwise (was successfuly updates)
	void updateTutorial(std::string old_title, std::string title, std::string presenter,
		int minutes, int seconds, int likes, std::string link);

	void updateTutorialWatchlist(std::string old_title, std::string title, std::string presenter,
		int minutes, int seconds, int likes, std::string link);

	// increments the likes of a tutorial with a given title if it exists
	// returns 1 if the tutorial exists, -1 otherwise
	void likeTutorial(std::string title);

	// deletes a tutorial from the tutorial list with a given title if it exists
	// returns 1 if the tutorial exists, -1 otherwise
	void deleteTutorial(std::string title);

	// deletes a tutorial from the watch list with a given title if it exists
	// returns 1 if the tutorial exists, -1 otherwise
	void deleteTutorialWatchList(std::string title);

	// returns a copy of the tutorial list
	std::vector<Tutorial*> getAllTutorials();

	// returns a copy of the watch list
	std::vector<Tutorial*> getAllTutorialsWatchList();

	// gets the number of elements of the tutorial list
	int getLengthTutorials();

	// gets the number of elements of the watch list
	int getLengthTutorialsWatchList();

	std::vector<Tutorial*> filterByPresenter(std::string given_presenter);

	// asigns 10 elements tot the tutorial list
	void assignRandom();
};