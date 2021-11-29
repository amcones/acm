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
const int maxn = 1e2 + 10;
const int mod = 1e9 + 7;
int n, m;
int mp[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int bfs(int sx, int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        PII t = q.front();
        if (t.first == n && t.second == m)
            return dis[n][m];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = t.first + dir[i][0], ty = t.second + dir[i][1];
            if (tx < 1 || ty < 1 || tx > n || ty > m || mp[tx][ty] || vis[tx][ty])
                continue;
            dis[tx][ty] = dis[t.first][t.second] + 1;
            vis[tx][ty] = 1;
            q.push({tx, ty});
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    cout << bfs(1, 1) << endl;
    return 0;
}