#ifndef LIBRARY_EXCEPTION_H
#define LIBRARY_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class LibraryException : public runtime_error {
public:
    LibraryException(const string& message) : runtime_error(message) {}
};

#endif
