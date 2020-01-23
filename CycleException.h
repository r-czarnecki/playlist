#ifndef CYCLEEXCEPTION_H
#define CYCLEEXCEPTION_H

#include "PlayerException.h"

class CycleException : public PlayerException {
protected:
    const char * playerExceptionInfo() const override;
};

#endif