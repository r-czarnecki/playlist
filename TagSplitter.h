#ifndef KLASY_TAGSPLITTER_H
#define KLASY_TAGSPLITTER_H

#include <map>
#include <memory>

class TagSplitter {
public:
    using tagMap = std::map<std::string, std::string>;

    static tagMap splitTags(const std::string& description);

    static std::string getContent(const std::string &description);

    static std::string TAG_DELIMETER();
    static std::string VALUE_DELIMETER();
};

#endif //KLASY_TAGSPLITTER_H
