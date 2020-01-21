#ifndef KLASY_FILE_H
#define KLASY_FILE_H

#include <string>

class File {
private:
    std::string type;
    std::string fileDescription;

public:
    explicit File(const std::string& fd);

    std::string getType() { return type; }
    std::string getDescription() { return fileDescription; }
};

#endif //KLASY_FILE_H
