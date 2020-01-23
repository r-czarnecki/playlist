#include <regex>

#include "File.h"
#include "TagSplitter.h"
#include "CorruptFileException.h"

File::File(const std::string& fd) {
    std::string delimeter = TagSplitter::TAG_DELIMETER();
    auto first_delimeter = fd.find_first_of(delimeter);

    if (first_delimeter == std::string::npos)
        throw CorruptFileException();

    type = fd.substr(0, first_delimeter);
    fileDescription = fd.substr(first_delimeter + 1);
}
