#ifndef KLASY_CORRUPTTAGEXCEPTION_H
#define KLASY_CORRUPTTAGEXCEPTION_H


#include "PlayerException.h"

class CorruptTagException : public PlayerException {
protected:
    const char *playerExceptionInfo() const override;
};


#endif //KLASY_CORRUPTTAGEXCEPTION_H
