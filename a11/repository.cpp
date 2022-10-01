#include "repository.h"
#include <windows.h>
#include <shellapi.h>
using namespace std;

Repository::Repository() {
	filePath = "";
}

Repository::Repository(std::string _filePath) {
	filePath = _filePath;
}

Repository::~Repository() {
	for (auto entity : tutorials) {
		delete entity;
	}
}

std::string Repository::getFilePath() {
	return filePath;
}

void Repository::readEntitiesFromFile() {
	ifstream f(filePath);
	if (!f.is_open()) {
		return;
	}

	Tutorial t{};
	while (f >> t) {
		try {
			TutorialValidator::validate(t);

			// duplicated entitites are not added to the repo!!!
			try {
				addTutorial(t);
			}
			catch (RepositoryException& re) {
				//throw;
			}
		}
		catch (ValidationException& ve) {
			throw;
		}
	}

	f.close();
}

void Repository::writeEntitiesToFile() {
	ofstream f(filePath);
	if (!f.is_open()) {
		return;
	}

	vector<Tutorial*> entities = tutorials;
	for (auto entity : entities) {
		f << *entity;
	}

	f.close();
}

void Repository::openFileExternal() {
	string command = "notepad.exe " + filePath;
	system(command.c_str());
}

void Repository::validate(const Tutorial& tutorial) {
	validator.validate(tutorial);
}

int Repository::getSizeTutorials() {
	return static_cast<int>(tutorials.size());
}

vector<Tutorial*> Repository::getAllTutorials() {
	return tutorials;
}

int Repository::findByTitleNoExcept(std::string title) {
	for (int i = 0; i < getSizeTutorials(); i++) {
		if (tutorials[i]->getTitle() == title) {
			return i;
		}
	}
	return -1;
}

void Repository::addTutorial(const Tutorial& tutorial) {
	validator.validate(tutorial);
	int pos = findByTitleNoExcept(tutorial.getTitle());
	if (pos != -1) {
		throw RepositoryException("The tutorial already exists!\n");
	}
	Tutorial* t = new Tutorial{ tutorial };
	tutorials.push_back(t);
}

void Repository::deleteTutorial(string title) {
	try {
		int pos = findByTitle(title);
		delete tutorials[pos];
		tutorials.erase(tutorials.begin() + pos);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

int Repository::findByTitle(std::string title) {
	for (int i = 0; i < getSizeTutorials(); i++) {
		if (tutorials[i]->getTitle() == title) {
			return i;
		}
	}
	throw RepositoryException("Title not found!");
}

void Repository::updateTutorial(std::string title, const Tutorial& tutorial) {
	validator.validate(tutorial);
	try {
		int pos = findByTitle(title);
		delete tutorials[pos];
		Tutorial* t = new Tutorial{ tutorial };
		tutorials[pos] = t;
	}
	catch (RepositoryException& re) {
		throw;
	}
}

void Repository::likeTutorial(std::string title) {
	try {
		int pos = findByTitle(title);
		tutorials[pos]->setLikes(tutorials[pos]->getLikes() + 1);
	}
	catch (RepositoryException& re) {
		throw;
	}
}

/*
	CSV repository overridden methods
*/

RepositoryCSV::RepositoryCSV() {
	filePath = "";
}

RepositoryCSV::RepositoryCSV(std::string _filePath) {
	filePath = _filePath;
}

RepositoryCSV::~RepositoryCSV() {
	for (auto entity : tutorials) {
		delete entity;
	}
}

void RepositoryCSV::readEntitiesFromFile() {
	ifstream f(filePath);
	if (!f.is_open()) {
		return;
	}

	Tutorial t{};
	while (f >> t) {
		try {
			TutorialValidator::validate(t);

			// duplicated entities are not added to the repo!!!
			try {
				addTutorial(t);
			}
			catch (RepositoryException& re) {
				//throw;
			}
		}
		catch (ValidationException& ve) {
			throw;
		}
	}

	f.close();
}

void RepositoryCSV::writeEntitiesToFile() {
	ofstream f(filePath);
	if (!f.is_open()) {
		return;
	}

	vector<Tutorial*> entities = tutorials;
	for (auto entity : entities) {
		f << *entity;
	}

	f.close();
}

void RepositoryCSV::openFileExternal() {
	string command = "notepad.exe " + filePath;
	system(command.c_str());
}

/*
	HTML repository overridden methods
*/

RepositoryHTML::RepositoryHTML() {
	filePath = "";
}

RepositoryHTML::RepositoryHTML(std::string _filePath) {
	filePath = _filePath;
}

RepositoryHTML::~RepositoryHTML() {
	for (auto entity : tutorials) {
		delete entity;
	}
}

void RepositoryHTML::readEntitiesFromFile() {
	ifstream f(filePath);
	if (!f.is_open()) {
		return;
	}

	std::string title;
	std::string presenter;

	std::string minutes;
	std::string seconds;
	std::string likes;

	std::string link;

	std::string line;
	for (int i = 0; i < 16; i++) {
		getline(f, line);
	} // reading till tutorial fields

	while (line == "<tr>") {
		getline(f, line);
		title = line.substr(4, line.find("/") - 4 - 1);

		getline(f, line);
		presenter = line.substr(4, line.find("/") - 4 - 1);

		getline(f, line);
		minutes = line.substr(4, line.find("/") - 4 - 1);

		getline(f, line);
		seconds = line.substr(4, line.find("/") - 4 - 1);

		getline(f, line);
		likes = line.substr(4, line.find("/") - 4 - 1);

		getline(f, line);
		getline(f, line);
		link = line.substr(1, line.find(">") - 1 - 1);

		Tutorial t{ title, presenter, Pair{ stoi(minutes), stoi(seconds) }, stoi(likes), link };

		try {
			TutorialValidator::validate(t);

			// duplicated entities are not added to the repo!!!
			try {
				addTutorial(t);
			}
			catch (RepositoryException& re) {
				//throw;
			}
		}
		catch (ValidationException& ve) {
			throw;
		}

		getline(f, line);
		getline(f, line);
	}

	f.close();
}

void RepositoryHTML::writeEntitiesToFile() {
	ofstream f(filePath);
	if (!f.is_open()) {
		return;
	}

	f << "<!DOCTYPE html>\n"
		"<html>\n"
		"<head>\n"
		"<title>Watchlist</title>\n"
		"</head>\n"
		"<body>\n"
		"<table border=\"1\">\n"
		"<tr>\n"
		"<td>Title</td>\n"
		"<td>Presenter</td>\n"
		"<td>Minutes</td>\n"
		"<td>Seconds</td>\n"
		"<td>Likes</td>\n"
		"<td>Link</td>\n";

	vector<Tutorial*> entities = tutorials;
	for (auto entity : entities) {
		f << "</tr>\n"
			"<tr>\n"
			"<td>" << entity->getTitle() << "</td>\n"
			<< "<td>" << entity->getPresenter() << "</td>\n"
			<< "<td>" << entity->getDuration().getFirst() << "</td>\n"
			<< "<td>" << entity->getDuration().getSecond() << "</td>\n"
			<< "<td>" << entity->getLikes() << "</td>\n"
			<< "<td>" << "<a href = \n" << "\"" << entity->getLink() << "\"" <<
			">Link</a></td>\n";
	}

	f << "</tr>\n"
		"</table>\n"
		"</body>\n"
		"</html>\n";

	f.close();
}

void RepositoryHTML::openFileExternal() {
	string link = "file:///C:/Users/User/source/repos/a11/" + filePath;
	ShellExecute(0, 0, wstring(link.begin(), link.end()).c_str(), 0, 0, SW_SHOW);
}