#ifndef KLASY_CORRUPTCONTENTEXCEPTION_H
#define KLASY_CORRUPTCONTENTEXCEPTION_H

#include "PlayerException.h"

class CorruptContentException : public PlayerException {
protected:
    const char * playerExceptionInfo() const override;
};

#endif //KLASY_CORRUPTCONTENTEXCEPTION_H
