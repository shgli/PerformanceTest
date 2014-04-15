#include "TimeFixture.h"
#define private public
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <complex>
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>

struct ProductFixture:TimeFixture
{
    ProductFixture()
    {
        for(size_t i = 0; i < SIZE; ++i)
        {
            ma[i] = i * 8 + 2;
            mb[i] = ma[i] + i * 2;
        }
    }

    static const size_t SIZE = 1024;
    float ma[SIZE];
    float mb[SIZE];
};

BOOST_FIXTURE_TEST_SUITE(DotProduct,ProductFixture)
    BOOST_AUTO_TEST_CASE(SerialTest)
    {
        SetAlgorithm("DotProduct");
        SetImplementation("serial");
        auto SerialProd = [](size_t n
                ,const float a[]
                ,const float b[]
                )->float
        {
            float result = 0.0;
            for(size_t i = 0; i < n; ++i)
            {
                result += a[i] * b[i];
            }

            return result;
        };

        float result = SerialProd(ProductFixture::SIZE,ma,mb);
        std::cout<<result<<std::endl;
    }

    BOOST_AUTO_TEST_CASE(SSETest)
    {
        SetAlgorithm("DotProduct");
        SetImplementation("see");
       
        auto SSEProd = [](size_t n
            ,const float a[]
            ,const float b[]
        )
        {
            assert(0 == n%4);
            __m128 res,prd,ma,mb;
            res = _mm_setzero_ps();
            for(size_t i = 0;i < n; i +=4)
            {
                ma = _mm_loadu_ps(&a[i]);
                mb = _mm_loadu_ps(&b[i]);
                prd = _mm_mul_ps(ma,mb);
                res = _mm_add_ps(prd,res);
            }
            prd = _mm_setzero_ps();
            //res = _mm_hadd_ps(res,prd);
            //res = _mm_hadd_ps(res,prd);

            float tmp;
            _mm_store_ss(&tmp,res);
            return tmp;
        };

        float result = SSEProd(SIZE,ma,mb);
        std::cout<<result<<std::endl;
    }

    BOOST_AUTO_TEST_CASE(TBBTest)
    {
        SetAlgorithm("DotProduct");
        SetImplementation("tbb");
 
        auto TbbProd = [](size_t n
            ,const float* a
            ,const float* b
            )->float
        {
            return tbb::parallel_reduce(
                    tbb::blocked_range<size_t>(0,n)
                    ,float(0)
                    ,[=](tbb::blocked_range<size_t>& title
                        ,float init)
                    {
                        return std::inner_product(
                            a + title.begin()
                            ,a+title.end()
                            ,b+title.begin()
                            ,init);
                    }
                    ,std::plus<float>()
                    );
        };
        float result = TbbProd(SIZE,ma,mb);
        std::cout<<result<<std::endl;
    }
        
BOOST_AUTO_TEST_SUITE_END()

