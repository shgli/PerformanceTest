#ifndef _DBFIXTURE_H
#define _DBFIXTURE_H
#include <vector>
#include <boost/pool/object_pool.hpp>
#include <boost/noncopyable.hpp>
#include "Performance.h"
class DBFixture
{
public:
    DBFixture();
    ~DBFixture();
};

class DBFixtureImpl
    :boost::noncopyable
{
public:
    static DBFixtureImpl& Instance()
    {
	static DBFixtureImpl instance;
	return instance;
    }

    Performance* NewPerformance( void );

    std::vector<Performance*> Performances() { return mPerformances; }
private:
    boost::object_pool<Performance> mPerformancePool;
    std::vector<Performance*> mPerformances;
};
#endif
 
