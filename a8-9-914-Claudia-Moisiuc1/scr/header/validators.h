//
// Created by dell on 21.04.2022.
//

#ifndef A8_9_914_CLAUDIA_MOISIUC_VALIDATORS_H
#define A8_9_914_CLAUDIA_MOISIUC_VALIDATORS_H

#endif //A8_9_914_CLAUDIA_MOISIUC_VALIDATORS_H
#include <string>
#include "tutorial.h"

class ValidationException{
private:
    std::string message;

public:
    ValidationException(std::string _message);
    std::string getMessage() const;
};

class ValidationExceptionInherited: public std::exception
{
private:
    std::string message;

public:
    ValidationExceptionInherited(std::string _message);
    const char* what() const noexcept override;
};

class TutorialValidator
{
public:
    static void validate(const Tutorial& t);
};
