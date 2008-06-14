#include "NullParamEx.h"

const char* NullParamEx::what() const throw()
{
	return "Parameter is null";
}

QString NullParamEx::message(void)
{
	return QString(what());
}
