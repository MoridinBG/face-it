#include "BadPathEx.h"

BadPathEx::~BadPathEx() throw()
{
	delete message_;
}

BadPathEx::BadPathEx(const char* path)
{
	message_ = strcat(message_, path);
}

BadPathEx::BadPathEx()
{
	message_ = "Given path is wrong or nonexistant. ";
}

const char* BadPathEx::what() const throw()
{
	return message_;
}

QString BadPathEx::message(void)
{
	return QString(what());
}
