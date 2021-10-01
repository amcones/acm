#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
ll mi[maxn];
ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res % mod * a % mod;
        a = a % mod * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll p)
{
    return power(a, p - 2, p);
}

//至少有一半升序
//注意逆元
int main()
{
    mi[1] = 1;
    for (int i = 2; i < maxn; i++)
        mi[i] = mi[i - 1] * i % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << mi[2 * n] * inv(2, mod) % mod << endl;
    }
    return 0;
}