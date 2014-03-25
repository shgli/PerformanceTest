#include "TimeFixture.h"
#define private public
#ifndef _WIN32
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <complex>
#include <tbb/parallel_for.h>

int Mandel(std::complex<double> c,int depth)
{
    int nCount = 0;
    std::complex<double> z = 0;
    for(int nStep = 0; nStep < depth; ++nStep)
    {
	if(std::abs(z) >= 2.0)
	{
	    break;
	}
	
	z = z * z + c;
	nCount++;
    }

    return nCount;
}

static const int MAX_ROW = 100;
static const int MAX_COL = 100;
static const int DEPTH = 1000000;
double Scale(int i)
{
    return 4.0 * ((double)i / MAX_ROW) - 2;
}

void Output(int result[MAX_ROW][MAX_COL])
{
    for(int iRow = 0; iRow < MAX_ROW; ++iRow)
    {
	for(int iCol = 0; iCol < MAX_COL; ++iCol)
	{
	    if(result[iRow][iCol] >= DEPTH)
	    {
		std::cout<<1;
	    }
	    else
	    {
		std::cout<<0;
	    }
	}
	std::cout<<std::endl;
    }
}

BOOST_FIXTURE_TEST_SUITE(Mandelbrot,TimeFixture)
    BOOST_AUTO_TEST_CASE(serialTest)
    {
        SetAlgorithm("Mandelbrot");
        SetImplementation("serial");
	int result[MAX_ROW][MAX_COL];
	for(int iRow = 0; iRow < MAX_ROW; ++iRow)
	{
	    for(int iCol = 0; iCol < MAX_COL; ++iCol)
	    {
		result[iRow][iCol] = Mandel(std::complex<double>(Scale(iRow),Scale(iCol)),DEPTH);
	    }
	}

	Output(result);

    }
   BOOST_AUTO_TEST_CASE(tbbTest)
   {
       SetAlgorithm("Mandelbrot");
       SetImplementation("tbb");

	int result[MAX_ROW][MAX_COL];
	tbb::parallel_for(0,MAX_ROW
		,[=,&result](int iRow)
	{
	    for(int iCol = 0; iCol < MAX_COL; ++iCol)
	    {
		result[iRow][iCol] = Mandel(std::complex<double>(Scale(iRow),Scale(iCol)),DEPTH);
	    }
	});

	Output(result);

   }
BOOST_AUTO_TEST_SUITE_END()
