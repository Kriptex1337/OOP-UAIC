#pragma once
#include <exception>

class OutOfRange : public std::exception
{
	virtual const char* what() const throw()
	{
		return "ERROR: Index out of range!";
	}
};
