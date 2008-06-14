#ifndef CPUCOUNT_H
#define CPUCOUNT_H

#include <QtGlobal>

#if defined(Q_WS_MAC)
    #include <sys/types.h>
    #include <sys/param.h>
    #include <sys/sysctl.h>

#elif defined(Q_WS_WIN)
    #include <windows.h>

#elif defined(Q_OS_LINUX)
    #include <unistd.h>

#endif

/**
Utility class used to detect the number of CPUs present on the system
	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class CpuCount
{
public:
	long count();

};

#endif
