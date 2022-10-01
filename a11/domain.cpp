#include "domain.h"
#include "validators.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Pair::Pair() {
	this->first = 0;
	this->second = 0;
}

Pair::Pair(int first, int second) {
	this->first = first;
	this->second = second;
}

Pair::Pair(const Pair& copy) {
	this->first = copy.first;
	this->second = copy.second;
}

int Pair::getFirst() const {
	return this->first;
}

void Pair::setFirst(const int& first) {
	this->first = first;
}

int Pair::getSecond() const {
	return this->second;
}

void Pair::setSecond(const int& second) {
	this->second = second;
}

// ---------------------------------------------------------

Tutorial::Tutorial() {
	this->title = "";
	this->presenter = "";
	this->duration.setFirst(0);
	this->duration.setSecond(0);
	this->likes = 0;
	this->link = "";
}

Tutorial::Tutorial(std::string title, std::string presenter, Pair duration, int likes, std::string link) {
	this->title = title;
	this->presenter = presenter;
	this->duration.setFirst(duration.getFirst());
	this->duration.setSecond(duration.getSecond());
	this->likes = likes;
	this->link = link;
}

Tutorial::Tutorial(const Tutorial& copy) {
	this->title = copy.title;
	this->presenter = copy.presenter;
	this->duration.setFirst(copy.duration.getFirst());
	this->duration.setSecond(copy.duration.getSecond());
	this->likes = copy.likes;
	this->link = copy.link;
}

std::string Tutorial::getTitle() const {
	return this->title;
}

void Tutorial::setTitle(std::string title) {
	this->title = title;
}

std::string Tutorial::getPresenter() const {
	return this->presenter;
}

void Tutorial::setPresenter(std::string presenter) {
	this->presenter = presenter;
}

Pair Tutorial::getDuration() const {
	return this->duration;
}

void Tutorial::setDuration(Pair duration) {
	this->duration = duration;
}

int Tutorial::getMinutes() const {
	return this->duration.getFirst();
}

void Tutorial::setMinutes(int minutes) {
	this->duration.setFirst(minutes);
}

int Tutorial::getSeconds() const {
	return this->duration.getSecond();
}

void Tutorial::setSeconds(int seconds) {
	this->duration.setSecond(seconds);
}

int Tutorial::getLikes() const {
	return this->likes;
}

void Tutorial::setLikes(int likes) {
	this->likes = likes;
}

std::string Tutorial::getLink() const {
	return this->link;
}

void Tutorial::setLink(std::string link) {
	this->link = link;
}

std::string Tutorial::toStr() const
{
	string ans;
	string duration_first = std::to_string(getDuration().getFirst());
	string duration_second = std::to_string(getDuration().getSecond());
	string likes = std::to_string(getLikes());
	ans = getTitle() + " | " + getPresenter() + " | " + duration_first +
		" | " + duration_second + " | " + likes + " | " + getLink();
	return ans;
}

vector<string> tokenize(string str, char delim) {
	vector<string> result;
	stringstream ss{ str };
	string token;
	while (getline(ss, token, delim)) {
		result.push_back(token);
	}
	return result;
}

std::istream& operator>>(std::istream& is, Tutorial& t) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');

	// making sure that the read tutorial data was valid
	if (tokens.size() != 6) {
		return is;
	}

	try {
		InputValidator::validateString(tokens[0]);
		InputValidator::validateString(tokens[1]);
		InputValidator::validateInt(tokens[2]);
		InputValidator::validateInt(tokens[3]);
		InputValidator::validateInt(tokens[4]);
		InputValidator::validateString(tokens[5]);

		t.title = tokens[0];
		t.presenter = tokens[1];
		t.duration.setFirst(stoi(tokens[2]));
		t.duration.setSecond(stoi(tokens[3]));
		t.likes = stoi(tokens[4]);
		t.link = tokens[5];
	}
	catch (ValidationException& ve) {
		//return is;
		throw;
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Tutorial& t) {
	os << t.title << ',' << t.presenter << ','
		<< t.duration.getFirst() << ',' << t.duration.getSecond() << ','
		<< t.likes << ',' << t.link << '\n';
	return os;
}