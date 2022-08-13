/***********************************
// @Author   :   amcones
// @Problem  :   D_Magical_Array.cpp
// @When     :   2022-08-01 09:21:52
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x;
            cin >> x;
            a[i] += x * j;
        }
    }
    int id = max_element(a.begin(), a.end()) - a.begin();
    cout << id + 1 << ' ' << a[id] - a[(id + 1) % n] << endl;
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