#include <memory>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/pgsql/database.hxx>
#include "DBFixture.h"
#include "Performance-odb.hxx"

DBFixture::DBFixture()
{
}

DBFixture::~DBFixture()
{
    using namespace odb::core;
    std::auto_ptr<database> pDatabase(new odb::pgsql::database());

    transaction t(pDatabase->begin());
    for(auto pPerformance : mPerformances)
    {
	pDatabase->persist(*pPerformance);
    }
    t.commit();
}

Performance* DBFixture::NewPerformance( void )
{
    auto pPerformance = mPerformancePool.construct();
    mPerformances.push_back(pPerformance);

    return pPerformance;
}


