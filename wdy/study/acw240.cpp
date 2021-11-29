/***********************************
// @Author   :   amcones
// @Problem  :   acw240.cpp
// @When     :   2021-11-23 17:43:48
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
const int maxn = 2e5 + 10;
int ans = 0;
int fa[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void comb(int x, int y) {
    fa[find(x)] = find(y);
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < maxn; i++)
        fa[i] = i;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (d == 1) {
            if (find(x) == find(y + n) || find(x) == find(y + n + n))
                ans++;
            else {
                comb(x, y), comb(x + n, y + n), comb(x + n + n, y + n + n);
            }
        } else if (d == 2) {
            if (x == y || find(x) == find(y) || find(x) == find(y + n))
                ans++;
            else {
                comb(x, y + n + n), comb(x + n, y), comb(x + n + n, y + n);
            }
        }
    }
    cout << ans << endl;
    return 0;
}