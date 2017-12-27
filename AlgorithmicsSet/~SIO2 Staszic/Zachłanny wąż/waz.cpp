#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 1000;

int64_t max(int64_t a, int64_t b)
{
    return a > b ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    uint16_t h, w;
    cin >> h >> w;
    static array<array<int64_t, MAX>, MAX> R;
    cin >> R[0][0];
    int64_t c;
    for(uint16_t x = 1; x < w; x++)
    {
        cin >> c;
        R[0][x] = R[0][x-1] + c;
    }
    for(uint16_t y = 1; y < h; y++)
    {
        cin >> c;
        R[y][0] = R[y-1][0] + c;
        for(uint16_t x = 1; x < w; x++)
        {
            cin >> c;
            R[y][x] = max(R[y][x-1], R[y-1][x]) + c;
        }
    }
    cout << R[h-1][w-1];
}
