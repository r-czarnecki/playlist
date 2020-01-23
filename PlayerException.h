//
// Created by wojtekk23 on 23.01.2020.
//

#ifndef KLASY_PLAYEREXCEPTION_H
#define KLASY_PLAYEREXCEPTION_H

#include <exception>
#include <string>

class PlayerException : public std::exception {
protected:
    virtual const char * playerExceptionInfo() const = 0;
public:
    const char * what() const noexcept override;
};

#endif //KLASY_PLAYEREXCEPTION_H
