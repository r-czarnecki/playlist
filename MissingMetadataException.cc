#include "MissingMetadataException.h"

const char *MissingMetaDataException::playerExceptionInfo() const {
   return missingTagMessage.c_str();
}

MissingMetaDataException::MissingMetaDataException(const char *tag)
: missingTag(tag) {
    missingTagMessage = "missing tag (" + missingTag + ")";
}
