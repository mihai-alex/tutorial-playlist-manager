#pragma once
#include <exception>
#include <string>

class ValidationException : public std::exception {
private:
	std::string message;

public:
	ValidationException(std::string _message);
	const char* what() const noexcept override;
};

class RepositoryException : public std::exception {
private:
	std::string message;

public:
	RepositoryException(std::string _message);
	const char* what() const noexcept override;
};