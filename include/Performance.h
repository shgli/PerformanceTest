#ifndef _PERFORMANCE_H
#define _PERFORMANCE_H

#include <string>
#include <cstdint>
#include <boost/timer/timer.hpp>
#include <odb/core.hxx>

#pragma db object
class Performance
{
public:
    Performance();

    std::string Algorithm;
    std::string Implementation;

    boost::date_time::ptime ComputeStartTime;
    uint64_t TotalTime;
    uint64_t UserTime;
    uint64_t SystemTime;
    uint_t PercentTime;
    bool IsDebug;
};
#endif
