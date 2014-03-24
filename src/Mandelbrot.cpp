#include "TimeFixture.h"
#include <boost/test/included/unit_test.hpp>
BOOST_FIXTURE_TEST_SUITE(Mandelbrot,TimeFixture)
   BOOST_AUTO_TEST_CASE(tbbTest)
   {
       SetAlgorithm("Mandelbrot");
       SetImplementation("tbb");
   }
BOOST_AUTO_TEST_SUITE_END()
