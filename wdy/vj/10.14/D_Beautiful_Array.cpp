/***********************************
// @Author   :   amcones
// @Problem  :   D_Beautiful_Array.cpp
// @When     :   2021-10-14 19:45:20
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
const int maxn = 3e5 + 10;
ll a[maxn];
ll dp[3][maxn];
// dp?
// 一部分直接加，一部分*k，剩下的再直接加
int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[0][i] = max(0ll, a[i] + dp[0][i - 1]);
        dp[1][i] = max(dp[0][i], dp[1][i - 1] + a[i] * x);
        dp[2][i] = max(dp[1][i], dp[2][i - 1] + a[i]);
    }
    cout << *max_element(dp[2], dp[2] + 1 + n) << endl;
    return 0;
}