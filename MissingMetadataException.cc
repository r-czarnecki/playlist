#include <sstream>
#include "MissingMetadataException.h"

const char *MissingMetaDataException::playerExceptionInfo() const {
    std::stringstream ss;
    ss << "missing tag ";
    ss << "(" << missingTag << ")";

    // TODO: Napraw to

    const std::string& tmp(ss.str());
    const char* cstr = tmp.c_str();

    return cstr;
}
