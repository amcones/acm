/***********************************
// @Author   :   amcones
// @Problem  :   LuoguP1048.cpp
// @When     :   2021-12-29 18:52:05
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
int dp[maxn][maxn];
int v[maxn], w[maxn];
int main() {
    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= M; i++) {
        for (int j = T; j >= v[i]; j--) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[M][T];
    return 0;
}