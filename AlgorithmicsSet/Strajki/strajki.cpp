#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 500000;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    uint32_t cities;
    cin >> cities;
    static array<vector<uint32_t>, MAX> next_to;
    static array<uint32_t, MAX> active_next_to;
    for(uint32_t i = 0; i < cities - 1; i++)
    {
        uint32_t a, b;
        cin >> a >> b; a--; b--;
        next_to[a].push_back(b);
        active_next_to[a]++;
        next_to[b].push_back(a);
        active_next_to[b]++;
    }
    uint32_t scount;
    cin >> scount;
    uint32_t groups = 1;
    for(uint32_t s = 0; s < scount; s++)
    {
        int32_t iz;
        cin >> iz;
        uint32_t z = abs(iz) - 1;
        if(iz > 0)
        {
            for(uint32_t n : next_to[z])
                active_next_to[n]--;
            groups += active_next_to[z] - 1;
        }
        else
        {
            for(uint32_t n : next_to[z])
                active_next_to[n]++;
            groups -= active_next_to[z] - 1;
        }
        cout << groups << endl;
    }
}
