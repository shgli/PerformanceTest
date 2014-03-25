#include "TimeFixture.h"
#define private public
#ifndef _WIN32
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(Mandelbrot,TimeFixture)
   BOOST_AUTO_TEST_CASE(tbbTest)
   {
       SetAlgorithm("Mandelbrot");
       SetImplementation("tbb");
   }
BOOST_AUTO_TEST_SUITE_END()
