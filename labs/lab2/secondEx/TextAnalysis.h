#ifndef TEXTANALYSIS_H
#define TEXTANALYSIS_H
#include <fstream>
#include <sstream>
#include <iostream>

class TextAnalysis {
private:
    static bool isPunctuationMark(char c);
    static bool endsWith(const std::string &value, const std::string &ending);
public:
    static void readFromFile(const std::string& fileName);
};

#endif //TEXTANALYSIS_H
