#include <memory>
#include <iostream>
#include "TagSplitter.h"
#include "CorruptYearMetadataException.h"
#include "CorruptTagException.h"

TagSplitter::tagMap TagSplitter::splitTags(const std::string &description, bool omitLastMetadata) {
    tagMap newMap{};
    std::string tags;

    if (omitLastMetadata) {
        auto lastDelimeter = description.find_last_of(TAG_DELIMETER());
        tags = description.substr(0, lastDelimeter);
    }

    size_t pos = 0;
    std::string tag, name, value;
    while (true) {
        auto tagDelimeter = tags.find_first_of(TAG_DELIMETER(), pos);
        tag = tags.substr(pos, tagDelimeter-pos);

        pos = tagDelimeter + 1;

        auto valDelimeter = tag.find_first_of(VALUE_DELIMETER());

        if (valDelimeter == std::string::npos) {
            throw CorruptTagException();
        }

        name = tag.substr(0, valDelimeter);
        value = tag.substr(valDelimeter + 1);

        newMap[name] = value;

        if (tagDelimeter == std::string::npos)
            break;
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
    static std::regex CONTENT_REGEX("^[" + ALPHANUMERIC_WHITESPACE_CHARACTERS() + ALLOWED_CONTENT_CHARACTERS() + "]*$");

    return CONTENT_REGEX;
}

std::string TagSplitter::ALLOWED_CONTENT_CHARACTERS() {
    // Escape hypen so that it does not have to be positionally dependent
    return ",.!?':;\\-";
}

int TagSplitter::PARSE_NUMERIC_TAG(const std::string& yearTagValue) {
    if (!std::regex_match(yearTagValue, std::regex("^[0-9]+$")))
        throw CorruptYearMetadataException();

    int year = std::stoi(yearTagValue);

    return year;
}

std::string TagSplitter::ALPHANUMERIC_WHITESPACE_CHARACTERS() {
    return "0-9a-zA-Z\\s";
}
