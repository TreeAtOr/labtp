#include "exception.h"
#include <exception>
#include <stdexcept>

libtp::exception::exception(const std::string &error, bool criticalError) : messageOfError(error),
                                                                         criticalError(criticalError) {}

std::string libtp::exception::getError() const {
    return messageOfError;
}

bool libtp::exception::isCriticalError() const {
    return criticalError;
}