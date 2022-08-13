/***********************************
// @Author   :   amcones
// @Problem  :   Watches.cpp
// @When     :   2022-08-01 12:07:58
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
const int maxn = 1e5 + 10;

PLL a[maxn];
ll n, m;

bool check(ll x) {
    ll sum = 0;
    sort(a + 1, a + 1 + n, [x](PII a, PII b) {
        return a.first + a.second * x < b.first + b.second * x;
    });
    for (int i = 1; i <= x; i++) {
        sum += a[i].first + a[i].second * x;
    }
    return sum <= m;
}

void init() {
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    ll l = 0, r = n;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else
            r = mid - 1;
    }
    cout << l << endl;
}
int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}