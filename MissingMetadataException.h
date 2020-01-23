#ifndef KLASY_MISSINGMETADATAEXCEPTION_H
#define KLASY_MISSINGMETADATAEXCEPTION_H

#include "PlayerException.h"

class MissingMetaDataException : public PlayerException {
private:
    std::string missingTag;

protected:
    const char *playerExceptionInfo() const override;

public:
    explicit MissingMetaDataException(const char *tag) : missingTag(tag) {};
};

#endif //KLASY_MISSINGMETADATAEXCEPTION_H
