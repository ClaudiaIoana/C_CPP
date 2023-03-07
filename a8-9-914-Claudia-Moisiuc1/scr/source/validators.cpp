//
// Created by dell on 21.04.2022.
//

#include "../header/validators.h"

using namespace std;

ValidationException::ValidationException(std::string _message): message{_message}
{
}

std::string ValidationException::getMessage() const {
    return this->message;
}

ValidationExceptionInherited::ValidationExceptionInherited(std::string _message): message{_message}
{
}

const char* ValidationExceptionInherited::what() const noexcept {
    return message.c_str();
}

void TutorialValidator::validate(const Tutorial &t) {
    string errors;
    if(t.getDuration().get_seconds() >= 60)
        errors += string("The seconds cannot be grater than 60.\n");
    if(t.getDuration().get_minutes() < 0)
        errors += string("Cannot have a negative number for minutes.\n");
    if(t.getDuration().get_seconds() < 0)
        errors += string("Cannot have a negative number for seconds.\n");
    if(t.getLikes() < 0)
        errors += string("Cannot have a negative number for like.\n");

    if(errors.size() > 0)
        throw ValidationException(errors);
}