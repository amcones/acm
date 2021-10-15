/***********************************
// @Author   :   amcones
// @Problem  :   D_Make_The_Fence_Great_Again.cpp
// @When     :   2021-10-11 20:55:50
***********************************/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 3e5 + 10;
//贪心？
//尽可能少操作，又要尽可能挑便宜
//dp
//每个点最多+2因为左右只有2个点
//从左边点的不同高度转移
ll dp[maxn][3];
int a[maxn], b[maxn];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
            dp[i][0] = dp[i][1] = dp[i][2] = 1e18;
        }
        dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = 2 * b[1];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i - 1] + k != a[i] + j)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
                }
            }
        }
        cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    }
    return 0;
}