#include <bits/stdc++.h>
#ifdef _WIN32
#define LL_FMT "%I64d"
#else
#define LL_FMT "%lld"
#endif

using namespace std;

typedef unsigned int uint32_t;
typedef long long int int64_t;

const size_t MAX = 500000;

int main()
{
    uint32_t n;
    scanf("%u", &n);
    static int64_t C[MAX], A[MAX], B[MAX];
    for(uint32_t i = 0; i < n; i++)
        scanf(LL_FMT, C+i);
    for(uint32_t i = 0; i < n - 1; i++)
        scanf(LL_FMT, A+i);
    for(uint32_t i = 0; i < n - 1; i++)
        scanf(LL_FMT, B+i+1);
    set<pair<int64_t, uint32_t> > D;
    static int64_t CD[MAX];
    CD[0] = A[0] - B[1];
    CD[n - 1] = B[n - 1] - A[n - 2];
    for(uint32_t i = 1; i < n - 1; i++)
        CD[i] = A[i] + B[i] - A[i - 1] - B[i + 1];
    for(uint32_t i = 0; i < n; i++)
        D.insert(make_pair(CD[i], i));
    static bool U[MAX];
    static uint32_t R[MAX];
    int64_t r = 0;
    for(uint32_t ri = 0; ri < n; ri++)
    {
        pair<int64_t, uint32_t> c = *D.begin();
        D.erase(D.begin());
        uint32_t i = c.second;
        r += C[i];
        R[ri] = i;
        U[i] = true;
        if(i < n - 1 and not U[i + 1])
        {
            C[i + 1] += A[i];
            D.erase(make_pair(CD[i + 1], i + 1));
            CD[i + 1] += A[i] - B[i + 1];
            D.insert(make_pair(CD[i + 1], i + 1));
        }
        if(i > 0 and not U[i - 1])
        {
            C[i - 1] += B[i];
            D.erase(make_pair(CD[i - 1], i - 1));
            CD[i - 1] += B[i] - A[i - 1];
            D.insert(make_pair(CD[i - 1], i - 1));
        }
    }
    printf(LL_FMT "\n", r);
    for(uint32_t i = 0; i < n; i++)
        printf("%u ", R[i] + 1);

}
