/***********************************
// @Author   :   amcones
// @Problem  :   P_1099_NOIP_2007_提高组_树网的核.cpp
// @When     :   2022-08-13 09:06:09
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
const int maxn = 1e3 + 10;

const int N = 1e4 + 10, M = 2e5 + 10;
int h[N], e[M], w[M], ne[M], tot;
void add(int u, int v, int c) {
    e[++tot] = v, w[tot] = c, ne[tot] = h[u], h[u] = tot;
}

int dis[N], fa[N];
bool flag[N];
int far;

void dfs(int u, int pre) {
    fa[u] = pre;
    if (dis[u] > dis[far])
        far = u;
    for (int i = h[u]; i; i = ne[i]) {
        int to = e[i];
        if (!flag[to] && to != pre) {
            dis[to] = dis[u] + w[i];
            dfs(to, u);
        }
    }
}

void init() {
}
void solve() {
    // memset(h, -1, sizeof h);
    int ans = 0x3f3f3f3f;
    int n, s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    int A, B;
    dis[1] = 1, dfs(1, 0), A = far;
    dis[far] = 0, dfs(A, 0), B = far;
    for (int i = B, j = B; i; i = fa[i]) {
        while (dis[j] - dis[i] > s)
            j = fa[j];
        int x = max(dis[B] - dis[j], dis[i]);  //更新到两个端点的最远距离
        ans = min(ans, x);
    }
    for (int i = B; i; i = fa[i])
        flag[i] = 1;
    for (int i = B; i; i = fa[i]) {  //把链上每一个点定为起点跑dfs以找到对于每一个点来说最远的距离
        dis[i] = 0;
        dfs(i, fa[i]);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dis[i]);
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