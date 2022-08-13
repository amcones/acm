/***********************************
// @Author   :   amcones
// @Problem  :   Ancestor.cpp
// @When     :   2022-07-25 13:17:15
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
const int maxn = 2e5 + 5;
struct edge {
    int to, next;
};
struct tree {
    int w[maxn];
    int dep[maxn], fa[maxn][20];
    int head[maxn], tot;
    edge eg[maxn << 1];
} trA, trB;

void add(int x, int y, tree& tr) {
    tr.eg[tr.tot].to = y;
    tr.eg[tr.tot].next = tr.head[x];
    tr.head[x] = tr.tot++;
}

void bfs(int s, tree& tr) {
    memset(tr.dep, 0x3f, sizeof tr.dep);
    tr.dep[0] = 0, tr.dep[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = tr.head[t]; ~i; i = tr.eg[i].next) {
            int j = tr.eg[i].to;
            if (tr.dep[j] > tr.dep[t] + 1) {
                tr.dep[j] = tr.dep[t] + 1;
                q.push(j);
                tr.fa[j][0] = t;
                for (int k = 1; k <= 17; k++)
                    tr.fa[j][k] = tr.fa[tr.fa[j][k - 1]][k - 1];
            }
        }
    }
}
int lca(int a, int b, tree& tr) {
    if (tr.dep[a] < tr.dep[b])
        swap(a, b);
    for (int k = 17; k >= 0; k--)
        if (tr.dep[tr.fa[a][k]] >= tr.dep[b])
            a = tr.fa[a][k];
    if (a == b)
        return a;
    for (int k = 17; k >= 0; k--)
        if (tr.fa[a][k] != tr.fa[b][k]) {
            a = tr.fa[a][k];
            b = tr.fa[b][k];
        }
    return tr.fa[a][0];
}
int x[maxn];
int LA[maxn], LB[maxn], PA[maxn], PB[maxn];
void init() {
    memset(trA.head, -1, sizeof trA.head);
    memset(trB.head, -1, sizeof trB.head);
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        cin >> trA.w[i];
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        add(i, p, trA), add(p, i, trA);
    }
    for (int i = 1; i <= n; i++)
        cin >> trB.w[i];
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        add(i, p, trB), add(p, i, trB);
    }
    bfs(1, trA), bfs(1, trB);
    LA[1] = LB[1] = x[1];
    PA[k] = PB[k] = x[k];
    for (int i = 2; i <= k; i++)
        LA[i] = lca(LA[i - 1], x[i], trA), LB[i] = lca(LB[i - 1], x[i], trB);
    for (int i = k - 1; i >= 1; i--)
        PA[i] = lca(PA[i + 1], x[i], trA), PB[i] = lca(PB[i + 1], x[i], trB);
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        if (i == 1) {
            if (trA.w[PA[i + 1]] > trB.w[PB[i + 1]])
                ans++;
        } else if (i == k) {
            if (trA.w[LA[i - 1]] > trB.w[LB[i - 1]])
                ans++;
        } else {
            if (trA.w[lca(LA[i - 1], PA[i + 1], trA)] > trB.w[lca(LB[i - 1], PB[i + 1], trB)])
                ans++;
        }
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