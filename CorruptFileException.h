#ifndef KLASY_CORRUPTFILEEXCEPTION_H
#define KLASY_CORRUPTFILEEXCEPTION_H

#include "PlayerException.h"

class CorruptFileException : public PlayerException {
protected:
    const char * playerExceptionInfo() const override;
};

#endif //KLASY_CORRUPTFILEEXCEPTION_H
