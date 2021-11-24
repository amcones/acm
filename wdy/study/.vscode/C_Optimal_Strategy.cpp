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
const int maxn = 1e6 + 10;
const int mod = 998244353;
int a[maxn];
int c[maxn];
ll mi(ll x)
{
    ll ans = 1;
    while (x--)
    {
        ans *= x;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mi(c[i]) % mod * c[i] / 2;
    }
    cout << ans << endl;
    return 0;
}