#include <bits/stdc++.h>
#define MAX 200000
#define SQUARE(x) (x*x)

using namespace std;

typedef pair<int64_t, int64_t> vec_t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int64_t vecs_n;
    cin >> vecs_n;
    static vec_t vecs[MAX];
    for(int64_t i = 0; i < vecs_n; i++)
        cin >> vecs[i].first >> vecs[i].second;
    static vec_t qvecs[8]; //quarter & axis vecs
    vec_t* avecs = qvecs + 4;
    for(int64_t i = 0; i < vecs_n; i++)
    {
        int64_t x = vecs[i].first, y = vecs[i].second;
        int64_t c = 4;
        if(x > 0)
        {
            if(y > 0)
                c = 0;
            else if(y < 0)
                c = 1;
        }
        else if(x < 0)
        {
            if(y < 0)
                c = 2;
            else if(y > 0)
                c = 3;
        }
        if(c < 4)
        {
            qvecs[c].first += x;
            qvecs[c].second += y;
        }
        if(y == 0)
        {
            if(x > 0) avecs[0].first += x;
            else if(x < 0) avecs[2].first += x;
        }
        if(x == 0)
        {
            if(y > 0) avecs[1].second += y;
            else if(y < 0) avecs[3].second += y;
        }
    }
    bitset<8> counter;
    int64_t maxim = 0;
    for(int64_t i = 0; i < (2 << 8); i++)
    {
        counter = bitset<8>(i);
        int64_t x = 0, y = 0;
        for(int64_t j = 0; j < 8; j++)
        {
            if(counter[j])
            {
                x += qvecs[j].first;
                y += qvecs[j].second;
            }
        }
        int64_t current = (x*x) + (y*y);
        if(current > maxim) maxim = current;
    }
    cout << maxim;
}
