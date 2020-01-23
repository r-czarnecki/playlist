#ifndef KLASY_CORRUPTYEARMETADATAEXCEPTION_H
#define KLASY_CORRUPTYEARMETADATAEXCEPTION_H

#include "PlayerException.h"

class CorruptYearMetadataException : public PlayerException{
protected:
    const char *playerExceptionInfo() const override;
};


#endif //KLASY_CORRUPTYEARMETADATAEXCEPTION_H
