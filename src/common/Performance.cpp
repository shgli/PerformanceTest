#include "Performance.h"
#include <boost/thread.hpp>
#include <sigar.h>
Performance::Performance()
{
#ifdef DEBUG
    IsDebug = true;
#else
    IsDebug = false;
#endif

    sigar_t *pSigar = nullptr;
    sigar_open(&pSigar);
    sigar_cpu_info_list_t cpuInfos;
    sigar_cpu_info_list_get(pSigar,&cpuInfos);
    NumOfCpu = cpuInfos.number;
    CPUName = std::string(cpuInfos.data[0].model);
    CacheSize = cpuInfos.data[0].cache_size;
    HardwareConcurrency = boost::thread::hardware_concurrency();
    TotalMemory = 0;
    AvaiableMemory = 0;
    sigar_cpu_info_list_destroy(pSigar,&cpuInfos);
    sigar_close(pSigar);
}

