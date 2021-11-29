#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int dis[600], vis[600];
int tot = 0;
int mp[600][600];
int n, m;
void prim(int x)
{
    memset(dis, 63, sizeof dis);
    dis[x] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mn = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (dis[j] < dis[mn]))
            {
                mn = j;
            }
        }
        vis[mn] = 1;
        tot += dis[mn];

        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == 0 && (mp[mn][j] < dis[j]))
            {
                dis[j] = mp[mn][j];
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int u, v, w;
    memset(mp, 0x3f, sizeof mp);
    while (m--)
    {
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = min(mp[u][v], w);
    }
    prim(1);
    if (tot >= 99999999 || tot <= -99999999)
        cout << "impossible\n";
    else
        cout << tot << endl;
    return 0;
}