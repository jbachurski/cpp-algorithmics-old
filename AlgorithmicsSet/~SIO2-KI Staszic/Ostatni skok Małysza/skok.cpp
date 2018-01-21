#include <bits/stdc++.h>

using namespace std;

const size_t MAX = 200000001;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    uint32_t n;
    cin >> n;
    static array<bool, MAX> prime;
    fill(prime.begin(), prime.begin()+n, true);
    prime[0] = prime[1] = false;
    for(uint32_t p = 2; p <= ceil(sqrt(n))+1; p++)
    {
        if(not prime[p])
            continue;
        for(uint32_t x = p*p; x <= n; x += p)
            prime[x] = false;
    }
    uint32_t s = 4, r = 0, bs = 4, br = 0;
    for(uint32_t i = 5; i <= n; i++)
    {
        if(not prime[i])
        {
            if(not prime[i-1])
                r++;
            else
                s = i;
        }
        if(br > r)
            bs = s, br = r;
    }
    cout << bs << " " << bs + br;
}
