/***********************************
// @Author   :   amcones
// @Problem  :   a.cpp
// @When     :   2021-12-11 10:21:42
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
const int mod = 1e9 + 7;
int n, m, k;
int a[51];
int dp[2][51];
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++)
            dp[i & 1][j] = 0;
        for (int j = 0; j < k; j++)
            for (int l = 1; l <= m; l++)
                (dp[i & 1][(j + a[l]) % k] += dp[(i & 1) ^ 1][j]) %= mod;
    }
    int ans = 0;
    for (int i = 1; i < k; i++) {
        if (i % 10 == 7 || i % 10 == 9)
            (ans += dp[n & 1][i]) %= mod;
    }
    cout << ans << endl;
    return 0;
}