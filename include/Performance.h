#ifndef _PERFORMANCE_H
#define _PERFORMANCE_H

#include <string>
#include <cstdint>
#include <boost/timer/timer.hpp>

class Performance
{
public:
    const std::string& getAlgorithmName() const { return mAlgorithmName; }
    void setAlgorithmName(const std::string& algorithmName) { mAlgorithmName = algorithmName; }
    const std::string& getImplementationName() const { return mImplementationName; }
    void setImplementationName(const std::string& implementationName) { mImplementationName = implementationName;}

private:
    std::string mAlgorithmName;
    std::string mImplementationName;
    bool mIsDebug;
    uint64_t mTotalTime;
    uint64_t mUserTime;
    uint64_t m

};
#endif
