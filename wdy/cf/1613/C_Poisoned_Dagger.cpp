/***********************************
// @Author   :   amcones
// @Problem  :   C_Poisoned_Dagger.cpp
// @When     :   2021-12-01 23:14:15
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
const int maxn = 1e5 + 10;
int a[200];
//刷新debuff
ll n, h;
bool check(ll k) {
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        if (a[i + 1] - a[i] > k)
            sum += k;
        else
            sum += a[i + 1] - a[i];
    }
    sum += k;
    // cout << sum << endl;
    if (sum >= h)
        return true;
    else
        return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> h;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll l = 1, r = 1e18;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}