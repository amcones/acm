#include <iostream>
#include <string>
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
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

ll p[63];
ll n, tot;
void insert(ll x)
{
    for (int i = 63; ~i; i--)
    {
        if (x & (1ll << i))
        {
            if (!p[i])
            {
                p[i] = x;
                tot++;
                break;
            }
            x ^= p[i];
        }
    }
}
bool check(ll x)
{
    for (int i = 63; ~i; i--)
    {
        if (x & (1ll << i))
        {
            if (!p[i])
                return false;
            x ^= p[i];
        }
    }
    return true;
}
ll qmax(ll res = 0)
{
    for (int i = 63; ~i; i--)
        res = max(res, res ^ p[i]);
    return res;
}
ll qmin()
{
    for (int i = 0; i <= 63; i++)
        if (p[i])
            return p[i];
}
void oper()
{
    for (int i = 1; i <= 63; i++)
        for (int j = 1; j <= i; j++)
            if (p[i] & (1ll << (j - 1)))
                p[i] ^= p[j - 1];
}
ll k_th(ll k)
{
    if (k == 1 && tot < n)
        return 0;
    if (tot < n)
        k--;
    oper();
    ll ans = 0;
    for (int i = 0; i <= 63; i--)
        if (p[i] != 0)
        {
            if (k & 1)
                ans ^= p[i];
            k /= 2;
        }
}
int main()
{

    return 0;
}