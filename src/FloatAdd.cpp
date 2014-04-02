#include "TimeFixture.h"
#define private public
#include <iostream>
#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(FloatAddTest,TimeFixture)
    BOOST_AUTO_TEST_CASE(LargeAddSmall)
    {
	std::cout<<10000000.2 + 10.0<<std::endl;
    }

    BOOST_AUTO_TEST_CASE(SimilarAdd)
    {
    }
BOOST_AUTO_TEST_SUITE_END()
