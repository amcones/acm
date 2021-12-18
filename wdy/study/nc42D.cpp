/***********************************
// @Author   :   amcones
// @Problem  :   nc42.cpp
// @When     :   2021-12-18 10:37:35
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
bool f = false;
int ans = 0x3f3f3f3f;
int x, y;
int fac(int x) {
    if (x == 1)
        return 1;
    return x * fac(x - 1);
}
void dfs(int x, int st) {
    if (st > 7)
        return;
    if (x == y) {
        ans = min(ans, st);
        f = true;
        return;
    }
    dfs(ceil(sqrt(x)), st + 1);
    dfs(floor(sqrt(x)), st + 1);
    if (x <= 13)
        dfs(fac(x), st + 1);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x == y) {
            cout << 0 << endl;
            continue;
        }
        f = false;
        ans = 0x3f3f3f3f;
        dfs(x, 0);
        if (!f)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}