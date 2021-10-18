/***********************************
// @Author   :   amcones
// @Problem  :   csust8004.cpp
// @When     :   2021-10-18 11:11:42
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
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
int n;
int fa[maxn][10];
int depth[maxn];
vector<int> e[maxn];
ll f[maxn][maxn];
ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll p) {
    return power(a, p - 2, p);
}
void bfs(int s) {
    memset(depth, 0, sizeof depth);
    queue<int> q;
    q.push(s);
    depth[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (!depth[v]) {
                depth[v] = depth[u] + 1;
                fa[v][0] = u;
                for (int i = 1; i < 9; i++) {
                    fa[v][i] = fa[fa[v][i - 1]][i - 1];
                }
                q.push(v);
            }
        }
    }
}
int lca(int a, int b, int u) {
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = 8; i >= 0; i--) {
        if (depth[fa[a][i]] >= depth[b]) {
            a = fa[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 8; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
ll calc(int u) {
    memset(fa, 0, sizeof fa);
    depth[u] = 1;
    bfs(u);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int p = lca(i, j, u);
            res = (res + f[depth[i] - depth[p]][depth[j] - depth[p]]) % mod;
        }
    }
    return res;
}
int main() {
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        f[i][0] = 1;
    ll tmp = inv(2, mod);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod * tmp % mod;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + 1LL * calc(i) * inv(n, mod) % mod) % mod;
    }
    cout << res << endl;
    return 0;
}