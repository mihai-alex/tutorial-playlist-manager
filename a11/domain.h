#pragma once
#include <string>
#include <iostream>

class Pair
{
private:
	int first;
	int second;

public:
	// constructors
	Pair();
	Pair(int first, int second);
	Pair(const Pair& copy);

	// getters and setters
	int getFirst() const;
	void setFirst(const int& first);

	int getSecond() const;
	void setSecond(const int& second);
};

class Tutorial
{
private:
	std::string title;
	std::string presenter;
	Pair duration;
	int likes;
	std::string link;

public:
	// constructors
	Tutorial();
	Tutorial(std::string title, std::string presenter, Pair duration, int likes, std::string link);
	Tutorial(const Tutorial& copy);

	// getters and setters
	std::string getTitle() const;
	void setTitle(std::string title);

	std::string getPresenter() const;
	void setPresenter(std::string presenter);

	Pair getDuration() const;
	void setDuration(Pair duration);

	int getMinutes() const;
	void setMinutes(int minutes);

	int getSeconds() const;
	void setSeconds(int seconds);

	int getLikes() const;
	void setLikes(int likes);

	std::string getLink() const;
	void setLink(std::string link);

	friend std::istream& operator>>(std::istream& is, Tutorial& t);
	friend std::ostream& operator<<(std::ostream& os, const Tutorial& t);
	std::string toStr() const;
};