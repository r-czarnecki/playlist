#include "CycleException.h"

const char *CycleException::playerExceptionInfo() const {
    return "playlists create a cycle";
}
