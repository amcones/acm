/***********************************
// @Author   :   amcones
// @Problem  :   acw902.cpp
// @When     :   2021-11-01 20:48:25
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
const int maxn = 1e4 + 10;
int dp[maxn][maxn];  // dp[i][j]将a[1～i]变成b[1～j]的操作方式的最小值
char a[maxn], b[maxn];
int main() {
    int n, m;
    cin >> n >> (a + 1) >> m >> (b + 1);
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + !(a[i] == b[j])});
        }
    }
    cout << dp[n][m];
    return 0;
}