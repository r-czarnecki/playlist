#include <sstream>
#include "MissingMetadataException.h"

const char *MissingMetaDataException::playerExceptionInfo() const {
    std::stringstream ss;
    ss << "missing tag ";
    ss << "(" << missingTag << ")";

    return ss.str().c_str();
}
