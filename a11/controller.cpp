#include "controller.h"
#include <iostream>
using namespace std;

Controller::Controller() {
	repository = new Repository{ "tutorials.txt" };
	fileWatchlistRepository = new Repository;
}

void Controller::allocWatchlistCSV() {
	delete fileWatchlistRepository;
	fileWatchlistRepository = new RepositoryCSV{ "watchlist_CSV.txt" };
}

void Controller::allocWatchlistHTML() {
	delete fileWatchlistRepository;
	fileWatchlistRepository = new RepositoryHTML{ "watchlist_HTML.htm" };
}

Controller::~Controller() {
	delete repository;
	delete fileWatchlistRepository;
}

void Controller::readTutorialsFromFile() {
	try {
		repository->readEntitiesFromFile();
	}
	catch (ValidationException& ve) {
		throw;
	}
}

void Controller::writeTutorialsToFile() {
	try {
		repository->writeEntitiesToFile();
	}
	catch (ValidationException& ve) {
		throw;
	}
}

void Controller::readWatchlistFromFile() {
	try {
		fileWatchlistRepository->readEntitiesFromFile();
	}
	catch (ValidationException& ve) {
		throw;
	}
}

void Controller::writeWatchlistToFile() {
	try {
		fileWatchlistRepository->writeEntitiesToFile();
	}
	catch (ValidationException& ve) {
		throw;
	}
}

void Controller::openFileExternal() {
	fileWatchlistRepository->openFileExternal();
}

void Controller::addTutorial(std::string title, std::string presenter,
	int minutes, int seconds, int likes, std::string link)
{
	Pair duration(minutes, seconds);
	Tutorial tutorial(title, presenter, duration, likes, link);

	try {
		repository->addTutorial(tutorial);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

void Controller::addTutorialObject(const Tutorial& tutorial) {
	try {
		repository->addTutorial(tutorial);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

void Controller::addTutorialToWatchList(const Tutorial& tutorial) {
	try {
		fileWatchlistRepository->addTutorial(tutorial);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

void Controller::updateTutorial(std::string old_title, std::string title, std::string presenter,
	int minutes, int seconds, int likes, std::string link)
{
	Pair updated_duration{ minutes, seconds };
	Tutorial updated_tutorial{ title, presenter, updated_duration, likes, link };
	try {
		repository->updateTutorial(old_title, updated_tutorial);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

void Controller::updateTutorialWatchlist(std::string old_title, std::string title, std::string presenter,
	int minutes, int seconds, int likes, std::string link)
{
	Pair updated_duration{ minutes, seconds };
	Tutorial updated_tutorial{ title, presenter, updated_duration, likes, link };
	try {
		fileWatchlistRepository->updateTutorial(old_title, updated_tutorial);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

void Controller::likeTutorial(std::string title) { // see this in watchlist repo
	repository->likeTutorial(title);
}

void Controller::deleteTutorial(std::string title) {
	repository->deleteTutorial(title);
}

void Controller::deleteTutorialWatchList(std::string title) {
	fileWatchlistRepository->deleteTutorial(title);
}

vector<Tutorial*> Controller::getAllTutorials() {
	return repository->getAllTutorials();
}

vector<Tutorial*> Controller::getAllTutorialsWatchList() {
	return fileWatchlistRepository->getAllTutorials();
}

int Controller::getLengthTutorials() {
	return repository->getSizeTutorials();
}

int Controller::getLengthTutorialsWatchList() {
	return fileWatchlistRepository->getSizeTutorials();
}

std::vector<Tutorial*> Controller::filterByPresenter(std::string given_presenter) {
	vector<Tutorial*> result;
	vector<Tutorial*> tutorials = getAllTutorials();
	if (given_presenter.length() != 0) {
		copy_if(tutorials.begin(), tutorials.end(), back_inserter(result),
			[given_presenter](Tutorial* t) { return given_presenter == t->getPresenter(); });

		return result;
	}
	else {
		return tutorials;
	}
}

void Controller::assignRandom() {
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
		likes = i;
		link = links[i];

		addTutorial(title, presenter, minutes, seconds, likes, link);
	}
}