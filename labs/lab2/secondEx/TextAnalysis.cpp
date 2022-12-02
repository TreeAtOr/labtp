#include "TextAnalysis.h"

bool TextAnalysis::isPunctuationMark(char c) {
    switch (c) {
        case ',':
        case '.':
        case ':':
        case ';':
        case '!':
        case '?':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
        case '<':
        case '>':
        case '"':
        case '-':
        case '\'':
            return true;
        default:
            return false;
    }
}

void TextAnalysis::readFromFile(const std::string &fileName) {
    if (!endsWith(fileName, ".txt")) {
        throw std::runtime_error("Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n");
    }

    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
        file.close();
        throw std::runtime_error("Файл не открылся!\n");
    }

    std::string word;
    std::string resultString;
    int counter = 0;

    while (file >> word) {
        bool firstCheck = isPunctuationMark(word[word.size() - 1]);

        bool secondCheck = isPunctuationMark(word[0]);

        bool thirdCheck = isPunctuationMark(word[0]) && isPunctuationMark(word[word.size() - 1]);

        if (firstCheck) word = word.substr(0, word.size() - 1);
        else if (secondCheck) word = word.substr(1, word.size());
        else if (thirdCheck) word = word.substr(1, word.size() - 2);

        if (word.length() <= 4) {
            ++counter;
            resultString.append(word + " ");
        }
    }

    if (counter == 0) {
        std::cout << "\nНет слов, состоящих не более чем из 4 букв!\n\n";
    } else {
        std::cout << "\nСлов, состоящих не более, чем из 4 букв: " << counter << "\n";
        std::cout << "Эти слова: " << resultString << "\n\n";
    }

    file.close();
}

bool TextAnalysis::endsWith(const std::string &value, const std::string &ending) {
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}