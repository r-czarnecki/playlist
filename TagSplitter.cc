#include <memory>
#include "TagSplitter.h"

TagSplitter::tagMap TagSplitter::splitTags(const std::string &description, bool omitLastMetadata) {
    tagMap newMap{};
    std::string tags;
    std::regex re("[^" + TAG_DELIMETER() + "]*");

    if (omitLastMetadata) {
        auto lastDelimeter = description.find_last_of(TAG_DELIMETER());
        tags = description.substr(0, lastDelimeter);
    }

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

std::string TagSplitter::decodeROT13(const std::string &text) {
    std::stringstream res;

    for (char c : text) {
        char nextCharacter = c;

        if ('a' <= nextCharacter && nextCharacter <= 'z') {
            nextCharacter -= 'a';
            nextCharacter -= 13;

            if (nextCharacter < 0)
                nextCharacter += 26;

            nextCharacter += 'a';
        }
        else if ('A' <= nextCharacter && nextCharacter <= 'Z') {
            nextCharacter -= 'A';
            nextCharacter -= 13;

            if (nextCharacter < 0)
                nextCharacter += 26;

            nextCharacter += 'A';
        }

        res << nextCharacter;
    }

    return res.str();
}

std::regex TagSplitter::ALLOWED_CONTENT_REGEX() {
    // TODO: Czy mamy matchować diakrytyki?
    static std::regex CONTENT_REGEX("^[0-9a-zA-Z\\s" + ALLOWED_CONTENT_CHARACTERS() + "]*$");

    return CONTENT_REGEX;
}

std::string TagSplitter::ALLOWED_CONTENT_CHARACTERS() {
    return ",.!?':;-";
}
