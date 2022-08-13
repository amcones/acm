/***********************************
// @Author   :   amcones
// @Problem  :   P_3387_模板_缩点.cpp
// @When     :   2022-08-10 15:21:36
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
vector<int> a;
vector<PII> eg;
const int N = 1e4 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], tot;

void add(int u, int v) {
    e[tot] = v, ne[tot] = h[u], h[u] = tot++;
}

int dfn[N], low[N], timestamp, scc_cnt, id[N], sum[N], in_stk[N];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk.push(u), in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (in_stk[j]) {
            low[u] = min(low[u], dfn[j]);
        }
    }
    if (dfn[u] == low[u]) {
        int y;
        scc_cnt++;
        do {
            y = stk.top();
            stk.pop();
            in_stk[y] = false;
            id[y] = scc_cnt;
            sum[scc_cnt] += a[y - 1];
        } while (y != u);
    }
}

int dp[N];

void dfs(int u) {
    if (dp[u])
        return;
    dp[u] = sum[u];
    int maxx = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dp[j])
            dfs(j);
        maxx = max(maxx, dp[j]);
    }
    dp[u] += maxx;
}

void init() {
}

void solve() {
    memset(h, -1, sizeof h);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    eg.resize(m);
    for (auto& i : a)
        cin >> i;
    for (auto& [u, v] : eg) {
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    memset(h, -1, sizeof h);
    memset(e, 0, sizeof e);
    memset(ne, 0, sizeof ne);
    tot = 0;
    for (auto& [u, v] : eg) {
        if (id[u] != id[v]) {
            add(id[u], id[v]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (!dp[i])
            dfs(i), ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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