/***********************************
// @Author   :   amcones
// @Problem  :   acw282.cpp
// @When     :   2021-11-01 21:18:49
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
const int maxn = 3e2 + 10;
int dp[maxn][maxn];
int a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = 0x3f3f3f3f;
            for (int i = l; i < r; i++) {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + a[r] - a[l - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}