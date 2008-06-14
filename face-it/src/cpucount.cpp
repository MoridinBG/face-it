//==============================================================================
//
// Copyright (c) 2007 Ryan Winter. All rights reserved.
//
// This file may be used under the terms of the GNU General Public
// License version 2.0 appearing in the file LICENSE packaged with this file.
//
//==============================================================================

//==============================================================================
//
// Modified in 2008 by Ivan Dilchovski for use in the neural network based
// face detection project.
// <root.darkstar@gmail.com>
//
//
//==============================================================================

#include "cpucount.h"

long CpuCount::count()
{
    long cpu_count = 1;

#if defined(Q_WS_MAC)
    int    mib[2] = { CTL_HW, HW_NCPU };
    int    cpus;
    size_t size = sizeof(cpus);
    if (0 == sysctl(mib, 2, &cpus, &size, NULL, 0))
    { 
        cpu_count = cpus;
    }

#elif defined(Q_WS_WIN)
    SYSTEM_INFO    si;
    GetSystemInfo(&si);
    cpu_count = si.dwNumberOfProcessors;

#elif defined(Q_OS_LINUX)
    cpu_count = sysconf(_SC_NPROCESSORS_ONLN);

#else
    #error unknown operating system

#endif

    if (cpu_count < 1) cpu_count = 1;

    return cpu_count;
}
