/***********************************
// @Author   :   amcones
// @Problem  :   1009.cpp
// @When     :   2022-07-26 12:08:03
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
const int mod = 998244353;

int p[maxn], q[maxn], s[maxn << 1];

void init() {
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    for (int i = 1; i <= 2 * n; i++) {
        cin >> s[i];
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