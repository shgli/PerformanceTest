#include "TimeFixture.h"
#include "DBFixture.h"
#include "Performance.h"
#include <boost/timer/timer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
class Timer
{
public:
    boost::timer::cpu_timer mTime;

    boost::timer::cpu_timer* operator->() {return &mTime;}
};
TimeFixture::TimeFixture()
{
    mTimer = new Timer();
    mPerformance = DBFixtureImpl::Instance().NewPerformance();
    mPerformance->ComputeStartTime = boost::posix_time::microsec_clock::local_time();
    (*mTimer)->start();
}

TimeFixture::~TimeFixture()
{
    (*mTimer)->stop();
    auto elapsed = (*mTimer)->elapsed();
    mPerformance->TotalTime = elapsed.wall;
    mPerformance->UserTime = elapsed.user;
    mPerformance->SystemTime = elapsed.system;
    mPerformance->PercentTime = 100 * (elapsed.user + elapsed.system) / (mPerformance->HardwareConcurrency * elapsed.wall) ;
}

void TimeFixture::SetAlgorithm(const std::string& algorithm)
{
    mPerformance->Algorithm = algorithm;
}

void TimeFixture::SetImplementation(const std::string& impl)
{
    mPerformance->Implementation = impl;
}

