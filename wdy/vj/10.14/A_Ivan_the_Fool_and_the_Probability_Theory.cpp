/***********************************
// @Author   :   amcones
// @Problem  :   A_Ivan_the_Fool_and_the_Probability_Theory.cpp
// @When     :   2021-10-14 20:00:49
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
//一行行考虑
//如果第一行有2块相同颜色那么后面的颜色都确定
//如果没有那就是分间的
//分间的第二行可能与第一行完全相同，或者错开
// dp[k][2]
//减去2种相间情况
ll dp[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    dp[1] = 2, dp[2] = 4;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
    cout << (dp[n] + dp[m] - 2) % mod;
    return 0;
}