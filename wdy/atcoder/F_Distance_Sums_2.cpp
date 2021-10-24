#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
vector<int> tr[maxn];
ll dis[maxn], son[maxn], n;
void dfs(int s, int fa, int d)
{
    dis[1] += d;
    for (auto i : tr[s]) {
        if (i == fa)
            continue;
        dfs(i, s, d + 1);
        son[s] += son[i];
    }
}
void dfs(int s, int fa)
{
    for (auto i : tr[s]) {
        if (i == fa)
            continue;
        dis[i] = dis[s] + n - 2ll * son[i];
        dfs(i, s);
    }
}
int main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        tr[u].push_back(v), tr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        son[i] = 1;
    dfs(1, -1, 0);
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        cout << dis[i] << endl;
    return 0;
}