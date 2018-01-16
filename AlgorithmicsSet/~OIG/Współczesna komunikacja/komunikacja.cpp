#include <bits/stdc++.h>
#if not(defined(_WIN32))
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using namespace std;

typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

const size_t MAX = 250000;
const size_t MAX_K = 13;

int main()
{
    uint32_t n, k;
    scanf("%u %u", &n, &k);
    static uint16_t U[MAX];
    static uint32_t C[1 << MAX_K];
    getchar();
    for(uint32_t i = 0; i < n; i++)
    {
        for(uint32_t j = 0; j < k; j++)
        {
            char v;
            if((v = getchar() - '0') != 0)
                U[i] |= v << j;
        }
        for(uint32_t c = 1; c < (1u << k); c++)
            if((c | U[i]) == U[i])
                C[c]++;
        getchar();
    }
    uint32_t r = 0;
    for(uint32_t i = 1; i < (1u << k); i++)
    {
        cout << bitset<MAX_K>(i) << " " << C[i] << endl;
        uint32_t c = __builtin_popcount(i);
        if(c == 1)
            r += C[i] * (C[i] - 1) / 2;
        else if(c == 2)
            r -= C[i] * (C[i] - 1) / 2;
    }
    printf("%u", r);
    r = 0;
    for(uint32_t i = 0; i < n; i++)
        for(uint32_t j = i+1; j < n; j++)
            if(U[i] & U[j])
                r++;
    printf("\n%u", r);
}
