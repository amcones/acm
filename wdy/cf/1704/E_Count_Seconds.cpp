/***********************************
// @Author   :   amcones
// @Problem  :   E_Count_Seconds.cpp
// @When     :   2022-08-01 10:52:39
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
const int maxn = 1e4 + 10;
const int mod = 998244353;
int n, m;

vector<int> eg[maxn];

ll a[maxn], in[maxn], q[maxn], u[maxn];

bool check() {
    for (int i = 1; i <= n; i++) {
        if (a[i])
            return true;
    }
    return false;
}

void init() {
    memset(in, 0, sizeof in);
    memset(u, 0, sizeof u);
    for (int i = 0; i < maxn; i++) {
        eg[i].clear();
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        eg[x].push_back(y);
        in[y]++;
    }
    int t = 0;
    while ((++t) <= n) {
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0 && u[i] == 0) {
                u[i] = 1, q[t] = i;
                for (int j : eg[i]) {
                    in[j]--;
                }
                break;
            }
        }
    }
    ll ans = 0;
    while (ans <= n && check()) {
        ans++;
        for (int i = n; i; i--) {
            if (a[q[i]]) {
                a[q[i]]--;
                for (int j : eg[i]) {
                    a[j]++;
                }
            }
        }
    }
    if (!check()) {
        cout << ans << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[q[i]] %= mod;
        for (int j : eg[q[i]]) {
            a[j] = (a[q[i]] + a[j]) % mod;
        }
    }
    cout << (ans + a[q[n]]) % mod << endl;
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