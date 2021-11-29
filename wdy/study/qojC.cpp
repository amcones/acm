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
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll t = min(a, b);
    ll ans = t * 2;
    a -= t, b -= t;
    if (a)
    {
        ll cnt = a / 3;
        ans += cnt * 3;
        a %= 3;
        if (a == 2)
            ans++;
    }
    else
    {
        ll cnt = b / 3;
        ans += cnt * 6;
        b %= 3;
        if (b == 2)
            ans += 4;
    }
    cout << ans << endl;
    return 0;
}