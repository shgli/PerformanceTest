#ifndef _PERFORMANCE_H
#define _PERFORMANCE_H

#include <string>
#include <cstdint>
#include <boost/timer/timer.hpp>
#include <odb/core.hxx>
#include <boost/date_time/posix_time/posix_time.hpp>

#pragma db object no_id
class Performance
{
public:
    Performance();

    std::string Algorithm;
    std::string Implementation;

#pragma db type("TIMESTAMP") not_null
    boost::posix_time::ptime ComputeStartTime;
    uint64_t TotalTime;
    uint64_t UserTime;
    uint64_t SystemTime;
    uint32_t PercentTime;
    uint32_t NumOfCpu;
    uint32_t CacheSize;
    uint32_t HardwareConcurrency;
    uint32_t TotalMemory;
    uint32_t AvaiableMemory;
    std::string CPUName;
    bool IsDebug;
};
#endif

