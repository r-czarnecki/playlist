#ifndef KLASY_FILE_H
#define KLASY_FILE_H

#include <string>

// TODO: Rozdzielać żetony w opisie pliku tutaj, czy w fabryce?

class File {
private:
    std::string type;
    std::string fileDescription;

public:
    File(std::string fd);

    std::string getType() { return type; }
    std::string getDescription() { return fileDescription; }
};

#endif //KLASY_FILE_H
