#ifndef _TIMEFIXTURE_H
#define _TIMEFIXTURE_H
#include <boost/timer/timer.hpp>
class Performance;
class TimeFixture
{
public:
    TimeFixture();
    ~TimeFixture();

    void SetAlgorithm(const std::string& algorithm);
    void SetImplementation(const std::string& impl);

private:
    boost::timer::cpu_timer mTimer;
    Performance* mPerformance;
};
#endif
