#include "CorruptTagException.h"

const char *CorruptTagException::playerExceptionInfo() const {
    return "corrupt tag (no separator)";
}
