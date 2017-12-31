#include <iostream>

using namespace std;

template<size_t MAX_SIZE = 1e5>
struct disjoint_set
{
    uint32_t parent_of[MAX_SIZE], rank_of[MAX_SIZE];
    disjoint_set(size_t n = MAX_SIZE)
    {
        for(uint32_t i = 0; i < n; i++)
        {
            parent_of[i] = i;
        }
        fill(rank_of, rank_of + MAX_SIZE, 0);
    }
    void unite(uint32_t first_node, uint32_t second_node)
    {
        uint32_t first = find_root(first_node);
        uint32_t second = find_root(second_node);
        if(rank_of[second] > rank_of[first])
        {
            parent_of[first] = second;
            rank_of[second]++;
        }
        else
        {
            parent_of[second] = first;
            rank_of[first]++;
        }
    }
    uint32_t find_root(uint32_t node)
    {
        if(parent_of[node] == node)
            return node;
        parent_of[node] = find_root(parent_of[node]);
        return parent_of[node];
    }
};
