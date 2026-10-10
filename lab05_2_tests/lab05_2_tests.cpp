
#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab052tests
{
    TEST_CLASS(lab052tests)
    {
    public:

        TEST_METHOD(TestArcthValue)
        {
            double x = 2.0;
            double expected = 0.5493061443;
            double actual = 0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, actual, 0.00001);
        }

        TEST_METHOD(TestSeriesSum)
        {
            double x = 2.0;
            double expected = 0.5416666667;
            double actual = 1.0 / (1 * pow(x, 1))
                + 1.0 / (3 * pow(x, 3));

            Assert::AreEqual(expected, actual, 0.00001);
        }

        TEST_METHOD(TestValueForThree)
        {
            double x = 3.0;
            double expected = 0.3465735903;
            double actual = 0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, actual, 0.00001);
        }
    };
}
