#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e2 + 10;
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)
            primes[x]++;
    }
    ll ans = 1;
    for (auto i : primes)
    {
        ll a = i.first, b = i.second;
        ll t = 1;
        while (b--)
            t = (t * a + 1) % mod;
        ans = ans * t % mod;
    }
    cout << ans << endl;
    return 0;
}