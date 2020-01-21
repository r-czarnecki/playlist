#include <memory>
#include <regex>
#include "TagSplitter.h"

TagSplitter::tagMap TagSplitter::splitTags(const std::string &description) {
    tagMap newMap{};

    std::regex re("[^" + TAG_DELIMETER() + "]*");
    auto lastDelimeter = description.find_last_of(TAG_DELIMETER());
    std::string tags = description.substr(0, lastDelimeter);

    for (std::sregex_iterator it = std::sregex_iterator(tags.begin(), tags.end(), re);
         it != std::sregex_iterator();
         ++it) {
        std::string tag = it->str();

        auto valDelimeter = tag.find_first_of(VALUE_DELIMETER());

        if (valDelimeter == std::string::npos) {
            // TODO: rzuć wyjątek (metadane bez separatora ':')
        }

        std::string name = tag.substr(0, valDelimeter);
        std::string value = tag.substr(valDelimeter + 1);

        newMap[name] = value;
    }

    return newMap;
}

std::string TagSplitter::getContent(const std::string &description) {
    auto lastDelimeter = description.find_last_of(TAG_DELIMETER());
    return description.substr(lastDelimeter + 1);
}

std::string TagSplitter::TAG_DELIMETER() {
    return "|";
}

std::string TagSplitter::VALUE_DELIMETER() {
    return ":";
}
