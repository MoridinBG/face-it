#ifndef BADPATHEX_H_
#define BADPATHEX_H_
#include "exception.h"
#include <QString>

class BadPathEx: public Exception
{
public:
	BadPathEx(const char* path);
	BadPathEx();
	~BadPathEx() throw();
	QString message(void);
	virtual const char* what() const throw();
private:
	char* message_;
};

#endif /*BADPATHEX_H_*/
