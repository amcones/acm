/***********************************
// @Author   :   amcones
// @Problem  :   1011.cpp
// @When     :   2022-07-28 15:15:12
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

void init() {
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    int pos = 0;
    for (int i = 63; i >= 0; i--) {
        for (int j = pos; j < n; j++) {  //找到最低位
            if ((a[j] >> i) & 1) {
                swap(a[pos], a[j]);
                break;
            }
        }
        if (!((a[pos] >> i) & 1))
            continue;
        for (int j = 0; j < n; j++) {  //只留下一个
            if (j == pos)
                continue;
            if ((a[j] >> i) & 1)
                a[j] ^= a[pos];
        }
        pos++;
        if (pos == n)
            break;
    }
    ll res = 0;
    for (int i = 0; i < pos; i++) {
        res ^= a[i];
    }
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
