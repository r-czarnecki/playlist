//
// Created by wojtekk23 on 23.01.2020.
//

#include "PlayerException.h"

const char * PlayerException::what() const noexcept {
    return playerExceptionInfo();
}
