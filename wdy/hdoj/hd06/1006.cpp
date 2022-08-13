/***********************************
// @Author   :   amcones
// @Problem  :   1006.cpp
// @When     :   2022-08-04 12:51:34
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

vector<int> mp[maxn];
int n;
int siz[maxn];

void init() {
    for (int i = 1; i <= n; i++)
        vector<int>().swap(mp[i]);
}

ll dfs2(int p, int f) {
    ll ans = 0;
    for (int i = 0; i < mp[p].size(); i++) {
        if (mp[p][i] == f)
            continue;
        ans = max(ans, siz[p] + dfs2(mp[p][i], p));
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v), mp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(mp[i].begin(), mp[i].end());
        siz[i] = unique(mp[i].begin(), mp[i].end()) - mp[i].begin();
    }
    cout << dfs2(1, 0) + 1 << endl;
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