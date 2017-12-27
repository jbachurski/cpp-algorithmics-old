#include <bits/stdc++.h>
#define MAX 500000
#define RMAX 1000000007
#define MINF(a, b) (a) < (b) ? (a) : (b)

using namespace std;

struct dir_t
{
    int64_t left, right, up, down;
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int64_t w, h, max_h;
    cin >> h >> w >> max_h;

    vector< vector<dir_t> > borders(h, vector<dir_t>(w));
    vector< vector<int64_t> > least_border(h, vector<int64_t>(w));
    int64_t i, j, c;
    for(i = 0; i < h; i++) for(j = 0; j < w; j++)
    {
        borders[i][j].left = borders[i][j].right = borders[i][j].up = borders[i][j].down = max_h;
        least_border[i][j] = max_h;
    }
    if(w > 1)
    {
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w - 1; j++)
            {
                cin >> c;
                least_border[i][j] = MINF(least_border[i][j], c);
                least_border[i][j+1] = MINF(least_border[i][j+1], c);
                borders[i][j].right = c;
                borders[i][j+1].left = c;
            }
        }
    }
    if(h > 1)
    {
        for(i = 0; i < h - 1; i++)
        {
            for(j = 0; j < w; j++)
            {
                cin >> c;
                least_border[i][j] = MINF(least_border[i][j], c);
                least_border[i+1][j] = MINF(least_border[i+1][j], c);
                borders[i][j].down = c;
                borders[i+1][j].up = c;
            }
        }
    }
    int64_t result = 1, min_border = max_h;
    for(i = 0; i < h; i++) for(j = 0; j < w; j++)
    {
        min_border = MINF(least_border[i][j], min_border);
        result *= (least_border[i][j] + 1);
        if(result > RMAX) result %= RMAX;
    }
    result += max_h - min_border;
    cout << result % RMAX;
}
