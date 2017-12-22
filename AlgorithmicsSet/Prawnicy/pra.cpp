#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

typedef unsigned long long int uint64_t;

int main()
{
    uint64_t workers_n, needed;
    cin >> workers_n >> needed;
    //scanf("%llu %llu", &workers_n, &needed);
    static pair<uint64_t, uint64_t> workers[MAX];
    map<pair<uint64_t, uint64_t>, uint64_t> original_index;
    for(uint64_t i = 0; i < workers_n; i++)
    {
        cin >> workers[i].first >> workers[i].second;
        //scanf("%llu %llu", &workers[i].first, &workers[i].second);
        original_index[workers[i]] = i;
    }
    sort(workers, workers + workers_n);
    uint64_t i1 = 0, i2 = 0;
    static pair<uint64_t, pair<bool, uint64_t> > timepoints[2 * MAX];
    for(uint64_t i = 0; i < workers_n; i++)
    {
        timepoints[2*i].first = workers[i].first;
        timepoints[2*i].second.first = false;
        timepoints[2*i].second.second = i;
        timepoints[2*i+1].first = workers[i].second;
        timepoints[2*i+1].second.first = true;
        timepoints[2*i+1].second.second = i;
    }
    sort(timepoints, timepoints + (2 * workers_n));
    static bool active[MAX], done_start[MAX];
    set<uint64_t> active_set, max_active_set, current_active_set;
    bool locked = false, found_new = true;
    uint64_t start, maxim = 0;
    while(found_new)
    {
        //printf("NEW\n");
        fill(active, active + MAX, false);
        active_set.clear(); locked = false;
        found_new = false;
        for(uint64_t i = 0; i < 2 * workers_n; i++)
        {
            uint64_t time = timepoints[i].first, index = timepoints[i].second.second;
            bool is_begin = not timepoints[i].second.first;
            //printf("%lld %d %lld", time, is_begin, index);
            if(is_begin)
            {
                active[index] = true;
                active_set.insert(index);
                if(not locked and active_set.size() >= needed and not done_start[index])
                {
                    //printf("--> lock\n");
                    locked = true;
                    start = time;
                    done_start[index] = true;
                    found_new = true;
                    current_active_set = active_set;
                }
            }
            else
            {

                active[index] = false;
                set<uint64_t>::iterator pos = active_set.find(index);
                if(pos != active_set.end())
                {
                    active_set.erase(pos);
                    if(locked and current_active_set.find(index) != current_active_set.end() and current_active_set.size() - 1 < needed)
                    {
                        //printf("--> unlock\n");
                        locked = false;
                        if(time - start > maxim)
                        {
                            max_active_set = active_set;
                            maxim = time - start;
                        }
                    }
                    current_active_set.erase(index);
                }
            }
            //printf("active %d\n", active_set.size());
        }
    }
    //printf("%llu\n", maxim);
    cout << maxim << endl;
    for(set<uint64_t>::iterator it = max_active_set.begin(); it != max_active_set.end(); ++it)
        //printf("%llu ", *it);
        cout << *it << " ";
}
