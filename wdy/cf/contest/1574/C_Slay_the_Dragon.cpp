#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
const int maxn = 2e5 + 10;
PLL d[maxn];
int main()
{
    ios::sync_with_stdio(false);
    ll n, m, sum = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> d[i].first >> d[i].second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        ll ans = 0;
        auto h = lower_bound(a.begin(), a.end(), d[i].first);
        ans = min(max(d[i].first - *h, 0ll) + max(0ll, d[i].second - sum + *h), (max(d[i].first - *(h - 1), 0ll) + max(0ll, d[i].second - sum + *(h - 1))));
        cout << ans << endl;
    }
    return 0;
}