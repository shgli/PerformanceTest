#include "TimeFixture.h"
#include "DBFixture.h"
#include "Performance.h"
#include <boost/timer/timer.hpp>
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
    (*mTimer)->start();
}

TimeFixture::~TimeFixture()
{
    (*mTimer)->stop();
    auto elapsed = (*mTimer)->elapsed();
    mPerformance->TotalTime = elapsed.wall;
    mPerformance->UserTime = elapsed.user;
    mPerformance->SystemTime = elapsed.system;
    mPerformance->PercentTime = 100 * (elapsed.user + elapsed.system) / elapsed.wall ;
}

void TimeFixture::SetAlgorithm(const std::string& algorithm)
{
    mPerformance->Algorithm = algorithm;
}

void TimeFixture::SetImplementation(const std::string& impl)
{
    mPerformance->Implementation = impl;
}

