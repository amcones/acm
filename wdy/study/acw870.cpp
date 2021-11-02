#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    ll ans = 1;
    cin >> n;
    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        if (x > 1)
            primes[x]++;
    }
    ll res = 1;
    for (auto p : primes)
        res = res * (p.second + 1) % mod;
    cout << res << endl;
    return 0;
}