#ifndef _TIMEFIXTURE_H
#define _TIMEFIXTURE_H
#include <string>
class Performance;
class Timer;
class TimeFixture
{
public:
    TimeFixture();
    ~TimeFixture();

    void SetAlgorithm(const std::string& algorithm);
    void SetImplementation(const std::string& impl);

private:
    Timer* mTimer;
    Performance* mPerformance;
};
#endif
