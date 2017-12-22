#include <bits/stdc++.h>
#define F(x) (a0+x*(a1+x*(a2+x*(a3+x*(a4+x*a5)))))

using namespace std;

const double precision = 0.00001;

int main()
{
    double a5, a4, a3, a2, a1, a0;
    cin >> a5 >> a4 >> a3 >> a2 >> a1 >> a0;
    double lo = -100000, hi = 100000;
    while(abs(hi - lo) > precision)
    {
        double x = (lo + hi) / 2;
        double x1 = (x + hi) / 2, x2 = (lo + x) / 2;
        cout << F(x1) << " " << F(x2) << endl;
        if(abs(F(x1)) < abs(F(x2)))
            lo = x;
        else
            hi = x;
    }
    cout << fixed << setprecision(4) << (lo + hi) / 2;
}
