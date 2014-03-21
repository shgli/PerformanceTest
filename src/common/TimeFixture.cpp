#include "TimeFixture.h"

TimeFixture::TimeFixture()
{
    mTimer.start();
}

TimeFixture::~TimeFixture()
{
    mTimer.stop();
    auto elapsed = mTimer.elapsed();
    mPerformance->TotalTime;
    mPerformance->UserTime;
    mPerformance->SystemTime;
    mPerformance->PercentTime;
}

void TimeFixture::SetAlgorithm(const std::string& algorithm)
{
    mPerformance->Algorithm = algorithm;
}

void TimeFixture::SetImplementation(const std::string& impl)
{
    mPerformance->Implementation = impl;
}

