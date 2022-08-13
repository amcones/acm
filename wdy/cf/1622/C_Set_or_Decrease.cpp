/***********************************
// @Author   :   amcones
// @Problem  :   C_Set_or_Decrease.cpp
// @When     :   2021-12-28 11:32:36
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
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 2e5 + 10;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        vector<ll> pref(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];
        ll ans = 9e18;
        for (int t = 0; t < n; t++) {
            ll cur = t;
            ll sum = pref[n - t] + a[0] * t;
            if (sum > k) {
                cur += (sum - k + t) / (t + 1);
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}