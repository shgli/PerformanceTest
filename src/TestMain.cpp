#include "DBFixture.h"
#ifndef _WIN32
#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MODULE PerformanceTest
#include <boost/test/unit_test.hpp>

BOOST_GLOBAL_FIXTURE(DBFixture)

