#include <cctype>
#include <memory>
#include <fstream>
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
    
    std::ifstream paramsFile("params.conf",std::ios::in | std::ios::binary);
    if(paramsFile.is_open())
    {
	std::string line;
	std::getline(paramsFile,line);

	int argc = 0;
	char* argv[8];
	for(int iPos = 0; iPos < line.length(); ++iPos)
	{
	    while(iPos < line.length() && std::isspace(line[iPos]))
	    {
		++iPos;
	    }

	    if(iPos < line.length())
	    {
		argv[argc] = new char[32];
		int iArgv = 0;
		while(iPos < line.length() && !std::isspace(line[iPos]))
		{
		    argv[argc][iArgv] = line[iPos];
		    iArgv++;
		    iPos++;
		}
		argv[argc][iArgv] = '\0';

		argc++;
	    }

	}

	
	std::auto_ptr<database> pDatabase(new odb::pgsql::database(argc,argv));

	transaction t(pDatabase->begin());
	for(auto pPerformance : DBFixtureImpl::Instance().Performances())
	{
	    pDatabase->persist(*pPerformance);
	}
	t.commit();
    }
}


Performance* DBFixtureImpl::NewPerformance( void )
{
    auto pPerformance = mPerformancePool.construct();
    mPerformances.push_back(pPerformance);
    return pPerformance;
}

