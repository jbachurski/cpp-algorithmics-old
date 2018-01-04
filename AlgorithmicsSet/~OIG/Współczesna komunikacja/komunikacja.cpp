#include <bits/stdc++.h>
#define MAX 250000
#define MAX_K 13

using namespace std;

typedef unsigned long long int uint64_t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    uint64_t n, k;
    cin >> n >> k;
    static uint64_t uses[MAX];
    static char buffer[MAX_K+1];
    for(uint64_t i = 0; i < n; i++)
    {
        cin >> buffer;
        for(uint64_t j = 0; j < k; j++)
            uses[i] += (buffer[j] == '1') << j;
    }
    uint64_t result = 0;
    for(uint64_t i = 0; i < n; i++)
    {
        for(uint64_t j = i + 1; j < n; j++)
        {
            if(uses[i] & uses[j])
                result++;
        }
    }
    cout << result;
}
