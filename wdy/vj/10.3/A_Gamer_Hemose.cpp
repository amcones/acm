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
ll a[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, h;
        cin >> n >> h;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n, greater<int>());
        int d = a[1] + a[2];
        int ans = h / d * 2;
        h %= d;
        if (h > 0)
        {
            ans++, h -= a[1];
        }
        if (h > 0)
        {
            ans++, h -= a[2];
        }
        cout << ans << endl;
    }
    return 0;
}