#ifndef exception_H
#define exception_H

#include <exception>
#include <iostream>
namespace libtp {
class exception : public std::exception {
private:
  std::string messageOfError;
  bool criticalError;

public:
  exception(const std::string &error, bool criticalError);

  bool isCriticalError() const;

  std::string getError() const;
};
} // namespace libtp

#endif // exception_H
