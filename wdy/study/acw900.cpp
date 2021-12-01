/***********************************
// @Author   :   amcones
// @Problem  :   acw900.cpp
// @When     :   2021-11-01 21:23:55
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
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
//计数dp
// int dp[maxn][maxn];
// int main() {
//     int n;
//     cin >> n;
//     dp[0][0] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % mod;
//         }
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//         ans = (ans + dp[n][i]) % mod;
//     cout << ans << endl;
//     return 0;
// }
//////////////////////////
//完全背包
int dp[maxn];
int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}