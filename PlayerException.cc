#include "PlayerException.h"

const char * PlayerException::what() const noexcept {
    return playerExceptionInfo();
}
