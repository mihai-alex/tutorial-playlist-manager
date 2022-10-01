#pragma once
#include "domain.h"
#include "exceptions.h"
#include "validators.h"
#include <fstream>
#include <string>
#include <vector>

class Repository {
protected:
	std::vector<Tutorial*> tutorials;
	TutorialValidator validator;
	std::string filePath;

public:
	// constructors
	Repository();
	Repository(std::string _filePath);
	~Repository();

	std::string getFilePath();

	virtual void readEntitiesFromFile();
	virtual void writeEntitiesToFile();

	virtual void openFileExternal();

	void validate(const Tutorial& tutorial);

	// gets the numebr of tutorials in the repository's tutorial list
	int getSizeTutorials();

	// gets a copy of the vector of tutorials from the repository
	std::vector<Tutorial*> getAllTutorials();

	int findByTitleNoExcept(std::string title);

	// adds a tutorial to the tutorial list in the repository
	void addTutorial(const Tutorial& tutorial);

	// deletes a tutorial in the repository's tutorial list found at a given position
	void deleteTutorial(std::string title);

	// searches for a tutorial in the list of tutorials from the repository
	// and returns it's position if it was found
	int findByTitle(std::string title);

	// searches for and updates a tutorial with a given title
	// returns 0 if the tutorial with the given title does not exist, 1 otherwise
	void updateTutorial(std::string title, const Tutorial& tutorial);

	// searhes for and increments a tutorial's likes, that has a given title
	// returns 0 if the tutorial with the given title does not exist, 1 otherwise
	void likeTutorial(std::string title);
};

class RepositoryCSV : public Repository {
public:
	RepositoryCSV();
	RepositoryCSV(std::string filePath);
	~RepositoryCSV();
	void readEntitiesFromFile() override;
	void writeEntitiesToFile() override;
	void openFileExternal() override;
};

class RepositoryHTML : public Repository {
public:
	RepositoryHTML();
	RepositoryHTML(std::string _filePath);
	~RepositoryHTML();
	void readEntitiesFromFile() override;
	void writeEntitiesToFile() override;
	void openFileExternal() override;
};