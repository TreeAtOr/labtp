#ifndef SAFEINPUT_H
#define SAFEINPUT_H
#include <iostream>
#include <string>

namespace libtp {
template <typename T> T input() {
  T answer;
  while (true) {
    std::cin.unsetf(std::ios::skipws);
    std::cout << "Ввод: ";
    std::cin >> answer;
    if (std::cin.good()) {
      std::cin.ignore(1000, '\n');
      return answer;
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Повторите попытку ввода, произошла ошибка!" << std::endl;
  }
}

template <> inline std::string input<std::string>() {
  std::string answer;
  std::cout << "Ввод: ";
  std::getline(std::cin, answer);
  return answer;
}

} // namespace libtp
#endif // SAFEINPUT_H
