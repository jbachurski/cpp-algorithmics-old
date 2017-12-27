#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 200000;

struct dt { bool s, k; };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    uint32_t n, m;
    cin >> n >> m;
    static array<vector<uint32_t>, MAX> graph;
    for(uint32_t i = 0; i < m; i++)
    {
        uint32_t a, b;
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    set<uint32_t> to_visit_all;
    static array<bool, MAX> visited;
    static array<char, MAX> status;
    for(uint32_t i = 0; i < n; i++)
        to_visit_all.insert(i);
    while(not to_visit_all.empty())
    {
        uint32_t start = *to_visit_all.begin();
        to_visit_all.erase(to_visit_all.begin());
        queue<uint32_t> to_visit;
        to_visit.push(start);
        visited[start] = true;
        status[start] = 'K';
        while(not to_visit.empty())
        {
            uint32_t current = to_visit.front();
            to_visit.pop();
            for(uint32_t c : graph[current])
            {
                if(not visited[c])
                {
                    to_visit_all.erase(c);
                    to_visit.push(c);
                    visited[c] = true;
                    status[c] = status[current] == 'K' ? 'S' : 'K';
                }
            }
        }
    }
    static array<dt, MAX> check;
    for(uint32_t i = 0; i < n; i++)
    {
        if(status[i] == 'K') check[i].k = true;
        else if(status[i] == 'S') check[i].s = true;
        for(uint32_t c : graph[i])
        {
            if(status[i] == 'K') check[c].k = true;
            else if(status[i] == 'S') check[c].s = true;
        }
    }
    for(uint32_t i = 0; i < n; i++)
    {
        if(not check[i].s or not check[i].k)
            goto fail;
    }
    cout << "TAK" << '\n';
    for(uint32_t i = 0; i < n; i++)
        cout << status[i] << '\n';
    return 0;
fail:
    cout << "NIE";
}
