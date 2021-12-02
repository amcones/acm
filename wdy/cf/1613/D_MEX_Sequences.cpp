/***********************************
// @Author   :   amcones
// @Problem  :   D_MEX_Sequences.cpp
// @When     :   2021-12-01 23:33:43
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
const int maxn = 5e5 + 10;
const int mod = 998244353;
ll dp1[maxn], dp2[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
            dp1[i] = dp2[i] = 0;
        dp1[0] = 1, dp2[0] = 1;
        ll ans = -1;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                (dp2[0] = dp2[0] * 2 + 1) %= mod;
            } else if (x >= 2) {
                (dp1[x + 1] += dp1[x + 1] + dp1[x]) %= mod;
                (dp2[x - 1] += dp2[x - 1] + dp1[x - 1]) %= mod;
                (dp2[x + 1] += dp2[x + 1]) %= mod;
            } else {
                dp1[1] = (dp1[1] * 2 + 1) % mod;
                (dp2[1] += dp2[1]) %= mod;
            }
        }
        for (int i = 0; i <= n + 1; i++) {
            (ans += dp1[i] + dp2[i]) %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}