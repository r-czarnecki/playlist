#ifndef POSITIONDOESNOTEXISTEXCEPTION_H
#define POSITIONDOESNOTEXISTEXCEPTION_H

#include "PlayerException.h"

class PositionDoesNotExistException : public PlayerException {
protected:
    const char * playerExceptionInfo() const override;
};

#endif