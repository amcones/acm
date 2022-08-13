#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define vec vector
#define str string
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
typedef long double db;
typedef long long ll;
const int N = (int)2e5 + 10;
int n, m;
vec<int> G[N];
int dep[N], f[N][20], lg[N];
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1, f[u][0] = fa;
    for (int i = 1; i <= lg[dep[u]]; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    while (dep[u] > dep[v]) {
        u = f[u][lg[dep[u] - dep[v]] - 1];
    }
    if (u == v)
        return v;
    for (int k = lg[dep[u]] - 1; k >= 0; k--) {
        if (f[u][k] != f[v][k]) {
            u = f[u][k];
            v = f[v][k];
        }
    }
    return f[u][0];
}
void sol(int TestCase) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v), G[v].pb(u);
    }
    dfs(1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << dep[lca(u, v)] - dep[1] << '\n';
    }
}
void init() {}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1, TestCase = 0;
    cin >> T;
    for (init(); T--;)
        sol(++TestCase);
    return 0;
}