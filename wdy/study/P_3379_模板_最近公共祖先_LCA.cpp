/***********************************
// @Author   :   amcones
// @Problem  :   P_3379_模板_最近公共祖先_LCA.cpp
// @When     :   2022-07-27 10:08:41
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
const int maxn = 5e5 + 10;

int h[maxn << 1], to[maxn << 1], nxt[maxn << 1], tot;  //建图
int son[maxn], sz[maxn], dep[maxn], fa[maxn];          //第一次dfs
int top[maxn], dfn[maxn], rnk[maxn], cnt;              //第二次dfs

void add(int u, int v) {
    to[++tot] = v;
    nxt[tot] = h[u];
    h[u] = tot;
}

void dfs1(int s) {
    son[s] = -1, sz[s] = 1;
    for (auto i = h[s]; i; i = nxt[i]) {
        if (auto t = to[i]; !dep[t]) {
            fa[t] = s;
            dep[t] = dep[s] + 1;
            dfs1(t);
            sz[s] += sz[t];
            if (son[s] == -1 || sz[son[s]] < sz[t])
                son[s] = t;
        }
    }
}

void dfs2(int s, int t) {
    top[s] = t;
    dfn[s] = ++cnt, rnk[cnt] = s;
    if (son[s] == -1)
        return;
    dfs2(son[s], t);
    for (auto i = h[s]; i; i = nxt[i]) {
        if (auto j = to[i]; j != son[s] && j != fa[s])
            dfs2(j, j);
    }
}

auto lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            y = fa[top[y]];
        else
            x = fa[top[x]];
    }
    return dep[y] < dep[x] ? y : x;
}

void init() {
}
void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    tuple<int, int> p;
    auto& [x, y] = p;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        apply(add, tuple(x, y));
        apply(add, tuple(y, x));
    }
    dep[s] = 1;
    dfs1(s), dfs2(s, s);
    while (m--) {
        cin >> x >> y;
        cout << apply(lca, p) << endl;
    }
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