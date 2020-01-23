#ifndef KLASY_FILE_H
#define KLASY_FILE_H

#include <string>
#include "TagSplitter.h"

class File {
private:
    std::string type;
    TagSplitter::tagMap tagMap;
    std::string fileDescription;

public:
    explicit File(const std::string& fd);

    std::string getType() { return type; }
    TagSplitter::tagMap getTagMap() { return tagMap; }
    std::string getDescription() { return fileDescription; }
};

#endif //KLASY_FILE_H
