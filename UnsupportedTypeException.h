#ifndef KLASY_UNSUPPORTEDTYPEEXCEPTION_H
#define KLASY_UNSUPPORTEDTYPEEXCEPTION_H

#include "PlayerException.h"

class UnsupportedTypeException : public PlayerException {
protected:
    const char * playerExceptionInfo() const override;
};

#endif //KLASY_UNSUPPORTEDTYPEEXCEPTION_H
