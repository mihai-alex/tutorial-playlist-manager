#pragma once
#include "domain.h"
#include "exceptions.h"

class TutorialValidator {
public:
	static void validate(const Tutorial& tutorial);
};

class InputValidator {
public:
	static void validateString(std::string str);
	static void validateInt(std::string num);
};