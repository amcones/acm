/***********************************
// @Author   :   amcones
// @Problem  :   P_3384_模板_轻重链剖分_树链剖分.cpp
// @When     :   2022-07-29 09:26:05
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;

int h[maxn << 1], to[maxn << 1], nxt[maxn << 1], tot;
int fa[maxn], son[maxn], siz[maxn], dep[maxn], w[maxn];
int dfn[maxn], rnk[maxn], top[maxn], cnt;
int tree[maxn << 2], mark[maxn << 2];
int n, m, r, p;

void add(int u, int v) {
    to[++tot] = v;
    nxt[tot] = h[u];
    h[u] = tot;
}

void dfs1(int s) {
    son[s] = -1, siz[s] = 1;
    for (int i = h[s]; i; i = nxt[i]) {
        if (int t = to[i]; !dep[t]) {
            dep[t] = dep[s] + 1;
            fa[t] = s;
            dfs1(t);
            siz[s] += siz[t];
            if (~son[s] || siz[son[s]] < siz[t])
                son[s] = t;
        }
    }
}
void dfs2(int s, int t) {
    top[s] = t;
    dfn[s] = ++cnt, rnk[cnt] = w[s];
    if (son[s] == -1)
        return;
    dfs2(son[s], t);
    for (int i = h[s]; i; i = nxt[i]) {
        int t = to[i];
        if (t != son[s] && t != fa[s])
            dfs2(t, t);
    }
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = rnk[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]) % p;
}

void push_down(int node, int len) {
    mark[node << 1] += mark[node];
    mark[node << 1 | 1] += mark[node];
    tree[node << 1] += mark[node] * (len - (len >> 1));
    tree[node << 1 | 1] += mark[node] * (len >> 1);
    tree[node << 1] %= p, tree[node << 1 | 1] %= p;
    mark[node] = 0;
}

void update(int node, int l, int r, int L, int R, int d) {
    if (L > r || R < l)
        return;
    else if (l >= L && r <= R) {
        tree[node] += (r - l + 1) * d;
        if (r > l)
            mark[node] += d;
    } else {
        ll mid = l + r >> 1;
        push_down(node, r - l + 1);
        update(node << 1, l, mid, L, R, d);
        update(node << 1 | 1, mid + 1, r, L, R, d);
        tree[node] = (tree[node << 1] + tree[node << 1 | 1] % p);
    }
}
int query(int node, int l, int r, int L, int R) {
    if (L > r || R < l)
        return 0;
    else if (l >= L && r <= R) {
        return tree[node] % p;
    } else {
        ll mid = l + r >> 1;
        push_down(node, r - l + 1);
        return (query(node << 1, l, mid, L, R) % p + query(node << 1 | 1, mid + 1, r, L, R) % p) % p;
    }
}

void updateRange(int x, int y, int z) {
    z %= p;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);                           //确保x始终在更深的链上
        update(1, 1, n, dfn[top[x]], dfn[x], z);  //更新x所在链
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update(1, 1, n, dfn[x], dfn[y], z);
}
int queryRange(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans = (ans + query(1, 1, n, dfn[top[x]], dfn[x])) % p;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ans = (ans + query(1, 1, n, dfn[x], dfn[y])) % p;
    return ans % p;
}
void updateSon(int x, int z) {
    update(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, z);
}
int querySon(int x) {
    return query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1) % p;
}

void init() {
}
void solve() {
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i < n; i++) {
        tuple<int, int> eg;
        auto& [x, y] = eg;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dep[r] = 1;
    dfs1(r), dfs2(r, r);
    build(1, 1, n);
    while (m--) {
        int op, x, y, z;
        cin >> op;
        switch (op) {
            case 1: {
                cin >> x >> y >> z;
                updateRange(x, y, z);
                break;
            }

            case 2: {
                cin >> x >> y;
                cout << queryRange(x, y) << endl;
                break;
            }
            case 3: {
                cin >> x >> z;
                updateSon(x, z);
                break;
            }
            case 4: {
                cin >> x;
                cout << querySon(x) << endl;
                break;
            }
        }
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