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
    sigar_cpu_info_list_destroy(pSigar,&cpuInfos);

    sigar_mem_t mem;
    sigar_mem_get(pSigar,&mem);
    TotalMemory = mem.total;
    AvaiableMemory = mem.free;
    sigar_close(pSigar);
}

