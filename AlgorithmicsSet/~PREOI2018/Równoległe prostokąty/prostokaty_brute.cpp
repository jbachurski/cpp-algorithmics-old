#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 100000;
typedef pair<int32_t, int32_t> pair_i32;



int main()
{
    uint32_t n;
    cin >> n;
    static array<pair_i32, MAX> P;
    static unordered_set<pair_i32> S;
    for(uint32_t i = 0; i < n; i++)
        cin >> P[i].first >> P[i].second, S.insert(P[i]);
    for(uint32_t i = 0; i < n; i++)
    {
        for(uint32_t j = i+1; j < n; j++)
        {

        }
    }

}
