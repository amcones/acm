/***********************************
// @Author   :   amcones
// @Problem  :   1001.cpp
// @When     :   2022-08-04 12:02:15
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
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;

int dp[maxn][2];  //第i个数字操作j满足非减序列的最少操作

int a[maxn];

void init() {
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
    }
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}