/***********************************
// @Author   :   amcones
// @Problem  :   1001.cpp
// @When     :   2022-07-29 10:59:44
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

int A[maxn], B[maxn], C[maxn];

ll h[maxn << 1], nxt[maxn << 1], p[maxn << 1], tot;  //建图
ll son[maxn], siz[maxn], dep[maxn], fa[maxn];        //第一个dfs求出父节点，深度，子树大小，重子节点
ll top[maxn], dfn[maxn], rnk[maxn], cnt;             //第二个dfs求出链顶，dfs序，dfs序对应节点编号
void add(int u, int v) {
    p[++tot] = v;
    nxt[tot] = h[u];
    h[u] = tot;
}
void dfs1(int o) {
    son[o] = -1;
    siz[o] = 1;
    for (int j = h[o]; j; j = nxt[j])
        if (!dep[p[j]]) {
            dep[p[j]] = dep[o] + 1;
            fa[p[j]] = o;
            dfs1(p[j]);
            siz[o] += siz[p[j]];
            if (son[o] == -1 || siz[p[j]] > siz[son[o]])
                son[o] = p[j];
        }
}

void dfs2(int o, int t) {
    top[o] = t;
    cnt++;
    dfn[o] = cnt, rnk[cnt] = o;
    rnk[cnt] = o;
    if (son[o] == -1)
        return;
    dfs2(son[o], t);  // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
    for (int j = h[o]; j; j = nxt[j])
        if (p[j] != son[o] && p[j] != fa[o])
            dfs2(p[j], p[j]);
}
struct Node {
    int l, r, sum[3], lz[4];
    void clear() {
        for (int i = 0; i < 3; i++)
            sum[i] = lz[i] = 0;
        lz[3] = 0;
    }
} tr[maxn << 2];
void build(int node, int l, int r) {
    tr[node] = {l, r};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(node << 1, l, mid), build(node << 1 | 1, mid + 1, r);
}
void pushup(int node) {
    for (int i = 0; i < 3; i++) {
        tr[node].sum[i] = tr[node << 1].sum[i] + tr[node << 1 | 1].sum[i];
    }
}
void eval(Node& t, int tag) {
    if (tag == 3)
        t.clear(), t.lz[3] = 1;
    else if (tag == 0) {
        t.sum[0] = t.r - t.l + 1;
        t.lz[0] = 1;
    } else if (tag == 1) {
        t.sum[1] = t.sum[0];
        t.lz[1] = 1;
    } else {
        t.sum[2] = t.sum[1];
        t.lz[2] = 1;
    }
}
void pushdown(int u) {
    if (tr[u].lz[3]) {
        eval(tr[u << 1], 3), eval(tr[u << 1 | 1], 3);
        tr[u].lz[3] = 0;
    }
    if (tr[u].lz[0]) {
        eval(tr[u << 1], 0), eval(tr[u << 1 | 1], 0);
        tr[u].lz[0] = 0;
    }
    if (tr[u].lz[1]) {
        eval(tr[u << 1], 1), eval(tr[u << 1 | 1], 1);
        tr[u].lz[1] = 0;
    }
    if (tr[u].lz[2]) {
        eval(tr[u << 1], 2), eval(tr[u << 1 | 1], 2);
        tr[u].lz[2] = 0;
    }
}
void modify(int u, int l, int r, int v) {
    if (tr[u].l >= l && tr[u].r <= r) {
        eval(tr[u], v);
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r, v);
    if (r > mid)
        modify(u << 1 | 1, l, r, v);
    pushup(u);
}
void update_path(int u, int v, int tag) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        modify(1, dfn[top[u]], dfn[u], tag);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    modify(1, dfn[v], dfn[u], tag);
}
void init() {
}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int r;
        cin >> r;
        add(i + 1, r), add(r, i + 1);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, n);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < a; i++) {
            cin >> A[i];
            update_path(1, A[i], 0);
        }
        for (int i = 0; i < b; i++) {
            cin >> B[i];
            update_path(1, B[i], 1);
        }
        for (int i = 0; i < c; i++) {
            cin >> C[i];
            modify(1, dfn[C[i]], dfn[C[i]] + siz[C[i]] - 1, 2);
        }
        //线段树维护三种标记
        cout << tr[1].sum[2] << endl;
        tr[1].clear();
        tr[1].lz[3] = 1;
    }
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