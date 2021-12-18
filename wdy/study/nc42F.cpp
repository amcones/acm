/***********************************
// @Author   :   amcones
// @Problem  :   nc42F.cpp
// @When     :   2021-12-18 11:02:51
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
int deg[maxn];
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int main() {
    int t = read();
    while (t--) {
        memset(deg, 0, sizeof deg);
        int n = read();
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            deg[read()]++, deg[read()]++;
        }
        for (int i = 1; i <= n; i++) {
            if (deg[i] >= 3)
                ans += n - 1 - deg[i];
        }
        cout << ans << endl;
    }
    return 0;
}