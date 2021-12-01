/***********************************
// @Author   :   amcones
// @Problem  :   acw897.cpp
// @When     :   2021-11-01 20:04:39
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
char a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
    int n, m;
    cin >> n >> m >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}