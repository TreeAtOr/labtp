#include "checkingAccuracyOfTheInput.h"
namespace libtp {
int checkingAccuracyOfTheInput(int low_limit, int high_limit) {
  int answer;
  while (true) {
    answer = libtp::input<int>();
    if (answer < low_limit || answer > high_limit) {
      std::cout << "Повторите попытку ввода, вводимое число должно быть в "
                   "диапазоне от "
                << low_limit << " до " << high_limit << "\n";
    } else
      break;
  }
  return answer;
}
} // namespace libtp