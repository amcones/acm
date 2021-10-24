/***********************************
// @Author   :   amcones
// @Version  :   1.0
// @Problem  :   _K_.cpp
// @When     :   2021-10-09 18:31:30
***********************************/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int N = 1e4 + 10, M = 2e5 + 10;
int h[N], rh[N], e[M], w[M], ne[M], tot;
int S, T, K;
int n, m;
void add(int* h, int u, int v, int c) {
    e[tot] = v, w[tot] = c, ne[tot] = h[u], h[u] = tot++;
}
ll dis[N];
bool vis[N];
void dij(int s)  //在反图上跑dij
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        if (vis[p])
            continue;
        vis[p] = true;
        for (int i = rh[p]; ~i; i = ne[i]) {
            int to = e[i];
            if (dis[to] > w[i] + dis[p]) {
                dis[to] = w[i] + dis[p];
                q.push({dis[to], to});
            }
        }
    }
}
int cnt[N];
int a_star() {
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    q.push({dis[S], {0, S}});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int ver = p.second.second, distance = p.second.first;
        cnt[ver]++;
        if (cnt[T] == K)
            return distance;
        for (int i = h[ver]; ~i; i = ne[i]) {
            int to = e[i];
            if (cnt[to] < K)
                q.push({distance + w[i] + dis[to], {distance + w[i], to}});
        }
    }
    return -1;
}
int main() {
    cin >> n >> m;
    int a, b, l;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    while (m--) {
        cin >> a >> b >> l;
        add(h, a, b, l), add(rh, b, a, l);
    }
    cin >> S >> T >> K;
    if (S == T)
        K++;
    dij(T);
    cout << a_star() << endl;
    return 0;
}
