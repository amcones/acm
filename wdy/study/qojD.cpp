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
PII a[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0, last = 0;
    for (int l = 1, r; l <= n; l = r)
    {
        r = l;
        while (r <= n && a[r].first == a[l].first)
            r++;
        ll t = max(last, a[r - 1].second);
        ans += (r - l) * t;
        last = t;
    }
    cout << ans << endl;
    return 0;
}