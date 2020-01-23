#ifndef KLASY_CORRUPTNUMERICMETADATAEXCEPTION_H
#define KLASY_CORRUPTNUMERICMETADATAEXCEPTION_H


#include "PlayerException.h"

class CorruptNumericMetadataException : public PlayerException {
protected:
    const char *playerExceptionInfo() const override;
};


#endif //KLASY_CORRUPTNUMERICMETADATAEXCEPTION_H
