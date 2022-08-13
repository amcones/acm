/***********************************
// @Author   :   amcones
// @Problem  :   LuoguP1048.cpp
// @When     :   2021-12-30 00:09:58
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
int lose[maxn], win[maxn], w[maxn];
ll dp[maxn];
int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> lose[i] >> win[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= w[i]; j--) {
            dp[j] = max(dp[j] + lose[i], dp[j - w[i]] + win[i]);
        }
        for (int j = w[i] - 1; j >= 0; j--) {
            dp[j] += lose[i];
        }
    }
    cout << 5ll * dp[x] << endl;
    return 0;
}