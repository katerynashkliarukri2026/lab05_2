#include <cmath>
#include "series.h"
#include "series.h"

double S(const double x, const double eps, int& n)
{
    double a = 1.0 / x;
    double s = a;

    n = 1;
    int k = 1;

    do
    {
        a = A(x, k, a);
        s += a;
        n++;
        k++;
    } while (abs(a) >= eps);

    return s;
}

double A(const double x, const int n, double a)
{
    double R = (2.0 * n - 1) /
        ((2.0 * n + 1) * x * x);

    a *= R;

    return a;
}