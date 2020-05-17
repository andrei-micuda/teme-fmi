#include "MyException.h"

MyException::MyException(const char* what_arg):what_arg(what_arg){}

const char* MyException::what() const noexcept {
	return this->what_arg;
}
