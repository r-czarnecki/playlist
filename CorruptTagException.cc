//
// Created by wojtekk23 on 23.01.2020.
//

#include "CorruptTagException.h"

const char *CorruptTagException::playerExceptionInfo() const {
    return "corrupt tag (no separator)";
}
