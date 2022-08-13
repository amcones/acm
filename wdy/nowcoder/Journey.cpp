/***********************************
// @Author   :   amcones
// @Problem  :   Journey.cpp
// @When     :   2022-07-25 14:51:43
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

map<int, PII> mp;
vector<int> p[maxn];
int tot;

void init() {
}
ll dis[maxn];
bool vis[maxn];
void dij(int u, int v) {
    fill(dis, dis + maxn, inf);
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        if (vis[p])
            continue;
        vis[p] = true;
        for (int i = head[p]; i != -1; i = eg[i].next) {
            int to = eg[i].to;
            dis[to] = min(dis[to], eg[i].w + dis[p]);
            if (!vis[to])
                q.push({dis[to], to});
        }
    }
}
void solve() {
    int n;
    cin >> n;
    int c[4];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> c[j];
            if (c[j] != 0)
                mp[tot++] = {i, c[j]}, mp[tot++] = {c[j], i};
            p[i].push_back(c[j]);
        }
    }
    PII s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    dij(s.first, s.second);
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