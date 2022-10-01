#include "validators.h"
#include <string>

void TutorialValidator::validate(const Tutorial& tutorial) {
	std::string errors;

	if (tutorial.getTitle().size() > 100 || tutorial.getTitle().size() == 0) {
		errors += std::string("The title can not be empty or over 100 characters!\n");
	}
	if (tutorial.getPresenter().size() > 100 || tutorial.getPresenter().size() == 0) {
		errors += std::string("The presenter can not be empty or over 100 characters!\n");
	}
	if (tutorial.getDuration().getFirst() < 0) {
		errors += std::string("The number of minutes can not be negative!\n");
	}
	if (tutorial.getDuration().getSecond() < 0) {
		errors += std::string("The number of seconds can not be negative!\n");
	}
	if (tutorial.getLikes() < 0) {
		errors += std::string("The number of likes can not be negative!\n");
	}
	if (tutorial.getLink().size() > 100 || tutorial.getLink().size() == 0) {
		errors += std::string("The link can not be empty or over 100 characters!\n");
	}

	if (errors.size() > 0) {
		throw ValidationException(errors);
	}
}

void InputValidator::validateString(std::string str) {
	if (str.size() > 100) {
		throw ValidationException("The string can not be over 100 characters!\n");
	}
}

void InputValidator::validateInt(std::string str) {
	for (auto digit : str) {
		if (!isdigit(digit)) {
			throw ValidationException("The string does not represent a positive integer!");
		}
	}
}