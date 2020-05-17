#pragma once
#include <exception>

class MyException : public std::exception {
	const char* what_arg;
public:
	MyException(const char*);
	~MyException() noexcept {}

	const char* what() const noexcept;
};