/***********************************
// @Author   :   amcones
// @Problem  :   B_Luke_is_a_Foodie.cpp
// @When     :   2022-08-01 10:35:41
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 2e5 + 10;

void init() {
}
void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    ll ans = 0;
    ll l = a[0] - x, r = a[0] + x;
    for (int i = 1; i < n; i++) {
        if (a[i] - x > r || a[i] + x < l) {
            l = a[i] - x, r = a[i] + x;
            ans++;
        }
        l = max(l, a[i] - x), r = min(r, a[i] + x);
    }
    cout << ans << endl;
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}