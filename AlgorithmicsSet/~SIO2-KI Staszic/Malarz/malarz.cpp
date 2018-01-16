#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 1000000000;
const size_t TSIZE = (1u << 5) + 1;
const size_t MASK_T = (1u << 31);
const size_t MASK_V = (1u << 31) - 1;

struct bit_toggle_tree
{
    array<uint32_t, TSIZE> nodes;
    void toggle_interval(uint32_t node, uint32_t tbegin, uint32_t tend, uint32_t sbegin, uint32_t send)
    {
        cout << "toggle_interval " << node << " " << tbegin << " " << tend << " " << sbegin << " " << send << " ";
        if(tend < sbegin or send < tbegin)
            cout << "-> 0" << endl;
        else if(sbegin <= tbegin and tend <= send)
        {
            cout << "-> 1" << endl;
            if(not (nodes[node] & MASK_T))
                nodes[node] = (tend - tbegin + 1 - (nodes[node] & MASK_V));
            nodes[node*2] ^= MASK_T;
            nodes[node*2+1] ^= MASK_T;
        }
        else
        {
            cout << "-> {} " << (nodes[node] & MASK_T) << endl;
            if(not (nodes[node] & MASK_T))
            {
                toggle_interval(node*2, tbegin, (tbegin+tend)/2, sbegin, send);
                toggle_interval(node*2+1, (tbegin+tend)/2+1, tend, sbegin, send);
                nodes[node] = (nodes[node*2]&MASK_V) + (nodes[node*2+1]&MASK_V);
            }
            else
            {
                nodes[node] ^= MASK_T;
                nodes[node] = (tend - tbegin + 1 - (nodes[node] & MASK_V));
            }
        }
    }
    void toggle_interval(uint32_t sbegin, uint32_t send)
    {
        return toggle_interval(1, 0, TSIZE/2-1, sbegin, send);
    }

    uint32_t find_sum(uint32_t node, uint32_t tbegin, uint32_t tend, uint32_t sbegin, uint32_t send)
    {
        cout << "find_sum " << node << " " << tbegin << " " << tend << " " << sbegin << " " << send << " ";
        if(nodes[node] & MASK_T)
        {
            nodes[node] = (tend - tbegin + 1 - (nodes[node] & MASK_V));
            nodes[node*2] ^= MASK_T;
            nodes[node*2+1] ^= MASK_T;
        }
        if(tend < sbegin or send < tbegin)
        {
            cout << "-> 0" << endl;
            return 0;
        }
        else if(sbegin <= tbegin and tend <= send)
        {
            cout << "-> " << (nodes[node] & MASK_V) << endl;
            return nodes[node] & MASK_V;
        }
        else
        {
            cout << "-> {}" << endl;
            return find_sum(node*2, tbegin, (tbegin+tend)/2, sbegin, send) +
                   find_sum(node*2+1, (tbegin+tend)/2+1, tend, sbegin, send);
        }
    }

    uint32_t find_sum(uint32_t sbegin, uint32_t send)
    {
        return find_sum(1, 0, TSIZE/2-1, sbegin, send);
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    uint32_t n, m;
    cin >> n >> m;
    static bit_toggle_tree tree;
    tree.toggle_interval(0, n-1);
    for(uint32_t i = 1; i < TSIZE-1; i++)
    {
        cout << "(" << ((bool)(tree.nodes[i] & MASK_T)) << ", " << (tree.nodes[i] & MASK_V) << "); ";
        if(__builtin_popcount(i+1) == 1)
            cout << endl;
    }
    cout << endl;
    cout << tree.find_sum(0, n-1) << endl;
    for(uint32_t mi = 0; mi < m; mi++)
    {
        char spec; uint32_t a, b;
        cin >> spec >> a >> b; a--; b--;
        if(spec == '*')
            tree.toggle_interval(a, b);
        else if(spec == '?')
            cout << tree.find_sum(a, b) << endl;
        for(uint32_t i = 1; i < TSIZE-1; i++)
        {
            cout << "(" << ((bool)(tree.nodes[i] & MASK_T)) << ", " << (tree.nodes[i] & MASK_V) << "); ";
            if(__builtin_popcount(i+1) == 1)
                cout << endl;
        }
        cout << endl;
    }
}
