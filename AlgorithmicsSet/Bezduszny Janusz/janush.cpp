#include <bits/stdc++.h>
#define MAX 100000
#define KILLED 1000000000
#define ABS_DIFF(a, b) b > a ? b - a : a - b

using namespace std;

int main()
{
    uint64_t N;
    cin >> N;
    static uint64_t population[MAX];
    for(uint64_t i = 0; i < N; i++)
    {
        cin >> population[i];
        population[i] %= KILLED;
    }
    static unordered_set<uint64_t> graph[MAX];
    uint64_t M;
    cin >> M;
    for(uint64_t i = 0; i < M; i++)
    {
        uint64_t a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    uint64_t Q;
    cin >> Q;
    for(uint64_t q = 0; q < Q; q++)
    {
        uint64_t source, revolt_size;
        cin >> source >> revolt_size;
        source--;
        population[source] += revolt_size;
        population[source] %= KILLED;
        queue<pair<uint64_t, uint64_t> > to_visit;
        to_visit.push(make_pair(source, 0));
        static bool revolted[MAX];
        fill(revolted, revolted + N, false);
        while(not to_visit.empty())
        {
            pair<uint64_t, uint64_t> current_pair = to_visit.front();
            uint64_t current = current_pair.first;
            uint64_t before_count = current_pair.second;
            to_visit.pop();
            uint64_t new_pop = 0, pop = population[current];
            pop %= KILLED;
            while(pop)
            {
                new_pop *= 10;
                new_pop += pop % 10;
                pop /= 10;
            }
            new_pop %= KILLED;
            population[current] = new_pop;
            if(before_count < revolt_size)
            {
                for(uint64_t target : graph[current])
                {
                    if(revolted[target])
                        continue;
                    to_visit.push(make_pair(target, before_count + 1));
                    revolted[target] = true;
                }
            }
        }
        uint64_t imax1 = 1, imax2 = 0;
        for(uint64_t i = 1; i < N; i++)
        {
            if(population[i] > population[imax1])
                imax1 = i;
        }
        for(uint64_t i = 0; i < N - 1; i++)
        {
            if(population[i] > population[imax2])
                imax2 = i;
        }
        uint64_t d1 = ABS_DIFF(population[imax1], population[0]);
        uint64_t d2 = ABS_DIFF(population[imax2], population[N - 1]);
        if(d1 > d2)
            cout << 1 << endl;
        else
            cout << N - 1 << endl;
    }
}
