#ifndef KLASY_TAGSPLITTER_H
#define KLASY_TAGSPLITTER_H

#include <map>
#include <memory>
#include <regex>

class TagSplitter {
public:
    using tagMap = std::map<std::string, std::string>;

    static tagMap splitTags(const std::string &description, bool omitLastMetadata = true);
    static std::string getContent(const std::string &description);

    static std::string decodeROT13(const std::string& text);

    static std::string TAG_DELIMETER();
    static std::string VALUE_DELIMETER();
    static std::string ALLOWED_CONTENT_CHARACTERS();
    static std::regex ALLOWED_CONTENT_REGEX();
};

#endif //KLASY_TAGSPLITTER_H
