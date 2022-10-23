#ifndef SAFEINPUTFROMFILE_H
#define SAFEINPUTFROMFILE_H
#include <string>
#include <fstream>
#include "exception.h"

using namespace libtp;

inline void is_error(std::fstream &file);

template<typename T>
T safeInputFromFile(std::fstream &file) {
    T answer;
    file >> answer;
    file.ignore();
    is_error(file);
    return answer;
}

template<>
inline std::string safeInputFromFile<std::string>(std::fstream &file) {
    std::string answer;
    std::getline(file, answer);
    is_error(file);
    return answer;
}

inline void is_error(std::fstream &file) {
    if (!file.good()) {
        file.close();
        throw exception("Часть данных из файла плохо обрабатывается!\n", true);
    }
}

#endif //SAFEINPUTFROMFILE_H
