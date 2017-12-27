#include <bits/stdc++.h>
#define MAX 200000
#define SQUARE(x) (x*x)
#define VEC_VAL(v) (SQUARE(v.first) + SQUARE(v.second))
#define VEC_ADD(a, b) make_pair((a).first + (b).first, (a).second + (b).second)
#define VEC_REPR(v) v.first << " " << v.second

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
    static vector<int64_t> vec_by_q[4];
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
            vec_by_q[c].push_back(i);
        }
        if(y == 0)
        {
            if(x > 0) avecs[0].first += x;
            else if(x < 0) avecs[2].first += x;
        }
        if(x == 0)
        {
            if(y < 0) avecs[1].second += y;
            else if(y > 0) avecs[3].second += y;
        }
    }
    int64_t maxim = 0, current;
    vec_t cvec, tvec;
    for(int64_t k = 0; k < 4; k++)
    {
        cvec = qvecs[k];
        switch(k)
        {
            case 0: cvec.first += avecs[0].first; cvec.second += avecs[3].second; break;
            case 1: cvec.first += avecs[0].first; cvec.second += avecs[1].second; break;
            case 2: cvec.first += avecs[2].first; cvec.second += avecs[1].second; break;
            case 3: cvec.first += avecs[2].first; cvec.second += avecs[3].second; break;
        }
        current = VEC_VAL(cvec);
        int64_t e = (k+1)%4, f = (k+3)%4;
        for(int64_t i = 0; i < vec_by_q[e].size(); i++)
        {
            tvec = VEC_ADD(cvec, vecs[vec_by_q[e][i]]);
            bool b = false;
            switch(k)
            {
                case 0: case 1: b = tvec.first > 0; break;
                case 2: case 3: b = tvec.first < 0; break;
            }
            if(b and VEC_VAL(tvec) > current)
            {
                cvec = tvec;
                current = VEC_VAL(cvec);
            }
        }
        for(int64_t i = 0; i < vec_by_q[f].size(); i++)
        {
            tvec = VEC_ADD(cvec, vecs[vec_by_q[f][i]]);
            bool b = false;
            switch(k)
            {
                case 0: case 3: b = tvec.second > 0; break;
                case 1: case 2: b = tvec.second < 0; break;
            }
            if(b and VEC_VAL(tvec) > current)
            {
                cvec = tvec;
                current = VEC_VAL(cvec);
            }
        }
        maxim = current > maxim ? current : maxim;
    }

    cout << maxim;
}
