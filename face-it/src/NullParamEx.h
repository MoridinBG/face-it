#ifndef NULLPARAMEX_H_
#define NULLPARAMEX_H_

#include "exception.h"
#include <QString>

class NullParamEx: public Exception
{
public:
	QString message(void);
	virtual const char* what() const throw();
};

#endif /*NULLPARAMEX_H_*/
