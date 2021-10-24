/***********************************
// @Author   :   amcones
// @Problem  :   csust10-23B.cpp
// @When     :   2021-10-23 21:58:24
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
const int maxn = 2e2 + 10;
int s[maxn];
int dp[maxn][maxn][8];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i], dp[i][i][s[i]] = 1;
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                for (int m = 0; m < 8; m++) {
                    for (int num1 = 0; num1 < 8; num1++) {
                        for (int num2 = 0; num2 < 8; num2++) {
                            if ((num1 + num2) / 2 == m)
                                dp[i][j][m] = max(dp[i][j][m], dp[i][k][num1] & dp[k + 1][j][num2]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        if (dp[1][n][i])
            cout << i << ' ';
    }
    return 0;
}