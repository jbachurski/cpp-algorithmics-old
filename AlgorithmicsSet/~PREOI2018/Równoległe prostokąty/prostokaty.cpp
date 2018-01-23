#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 100000;
typedef pair<int32_t, int32_t> point_t;

bool point_t_rev_less(const point_t& a, const point_t& b)
{
    return a.second < b.second or (not a.second < b.second and a.first < b.first);
}

template<typename T>
void uprint(T o)
{
    cerr << o;
}

template<typename A, typename B>
void uprint(pair<A, B> p)
{
    cerr << "(" << p.first << ", " << p.second << ")";
}

template <typename T, template <typename, typename...> class V, typename... Args>
void uprint(V<T, Args...>& it)
{
    cerr << "{";
    for(T i : it)
        uprint(i), cerr << "; ";
    cerr << "}";
}

int main()
{
    uint32_t n;
    cin >> n;
    static array<point_t, MAX> P;
    map<int32_t, vector<int32_t> > V, H; // Horizontal, Vertical
    unordered_map<int32_t, unordered_set<int32_t> > HS;
    for(uint32_t i = 0; i < n; i++)
    {
        cin >> P[i].first >> P[i].second;
        V[P[i].first].push_back(P[i].second);
        H[P[i].second].push_back(P[i].first);
        HS[P[i].second].insert(P[i].first);
    }
    sort(P.begin(), P.begin() + n);
    for(pair<int32_t, vector<int32_t> > p : V)
        sort(p.second.begin(), p.second.end());
    for(pair<int32_t, vector<int32_t> > p : H)
        sort(p.second.begin(), p.second.end());
    uint32_t result = 0;
    for(pair<int32_t, vector<int32_t> > cp : H)
    {
        int32_t& y1 = cp.first;
        vector<int32_t>& x_values = cp.second;
        for(int32_t x1 : x_values)
        {
            for(int32_t y2 : V[x1])
            {
                if(y2 > y1) for(int32_t x2 : H[y2])
                {
                    if(x2 > x1 and HS[y1].find(x2) != HS[y1].end() and HS[y2].find(x1) != HS[y2].end())
                        result++;
                }
            }
        }
    }
    cout << result;
}
