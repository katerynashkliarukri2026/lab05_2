
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s;
    int n = 0;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "eps = ";
    cin >> eps;

    if (xp > xk || dx <= 0 || eps <= 0 ||
        !((xp > 1) || (xk < -1)))
    {
        cout << "Error! Check input data." << endl;
        return 1;
    }

    cout << fixed;
    cout << "-----------------------------------------------------"
        << endl;

    cout << "|" << setw(8) << "x" << " |"
        << setw(14) << "Arcth(x)" << " |"
        << setw(14) << "S" << " |"
        << setw(8) << "n" << " |" << endl;

    cout << "-----------------------------------------------------"
        << endl;

    x = xp;

    while (x <= xk)
    {
        s = S(x, eps, n);

        cout << "|" << setw(8) << setprecision(3) << x << " |"
            << setw(14) << setprecision(6)
            << 0.5 * log((x + 1) / (x - 1)) << " |"
            << setw(14) << setprecision(6) << s << " |"
            << setw(8) << n << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------------------------------"
        << endl;

    return 0;
}

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
