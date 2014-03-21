#ifndef _DBFIXTURE_H
#define _DBFIXTURE_H
#include <vector>
#include <boost/pool/object_pool.hpp>
class Performance;
class DBFixture
{
public:
    DBFixture();
    ~DBFixture();

    Performance* NewPerformance( void );
private:
    boost::object_pool<Performance> mPerformancePool;
    std::vector<Performance*> mPerformances;
};
#endif
 
