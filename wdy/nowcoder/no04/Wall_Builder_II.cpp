/***********************************
// @Author   :   amcones
// @Problem  :   Wall_Builder_II.cpp
// @When     :   2022-07-30 15:21:47
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

int a[110];

void init() {
}
void solve() {
    int n;
    cin >> n;
    int S = 0;
    for (int i = 1; i <= n; i++) {
        int num = n + 1 - i;
        S += num * i;
        a[i] = num;
    }
    int m = sqrt(S);
    int l = 1, mind = 0x3f3f3f3f;
    for (int i = 1; i <= S; i++) {
        if (S % i != 0)
            continue;
        int j = S / i;
        if (i + j < mind) {
            mind = min(mind, i + j);
            l = i;
        }
    }
    int h = S / l;
    if (l < h)
        swap(l, h);
    cout << (h + l) * 2 << endl;
    int maxl = n;
    for (int i = 0; i < h; i++) {
        int x = 0;
        while (x < l) {
            int len = min(l - x, maxl);
            a[len]--;
            if (a[maxl] == 0)
                maxl--;
            cout << x << ' ' << i << ' ' << x + len << ' ' << i + 1 << endl;
            x = x + len;
        }
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