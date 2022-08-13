/***********************************
// @Author   :   amcones
// @Problem  :   不要_62.cpp
// @When     :   2022-08-10 19:30:55
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
int dp[10][15][15];  //需要保存最后一位的状态与前面位数的状态来唯一确定一个状态
int a[10];
int cnt;

int dfs(int pos, int last, int limit) {
    int ans = 0;
    if (pos == cnt)
        return 1;
    if (dp[pos][last][limit] != -1)
        return dp[pos][last][limit];
    for (int v = 0; v <= (limit ? a[pos] : 9); v++) {
        if (last == 6 && v == 2 || v == 4) {
            continue;
        }
        ans += dfs(pos + 1, v, limit && v == a[pos]);
    }
    return ans;
}

int f(int x) {
    memset(a, 0, sizeof a);
    memset(dp, -1, sizeof dp);
    cnt = 0;
    while (x)
        a[cnt++] = x % 10, x /= 10;
    reverse(a, a + cnt);
    return dfs(0, 11, 1);
}

void init() {
}
void solve() {
    int n, m;
    cin >> n >> m;
    cout << f(m) - f(n - 1) << endl;
}
int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}