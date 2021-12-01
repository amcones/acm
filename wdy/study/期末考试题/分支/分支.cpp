// Created on James的iPad.

#include <iostream>
using namespace std;
const int maxn = 1e3 + 10;
char mp[maxn][maxn];
int ans = 0;
int n, m;
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
bool vis[maxn][maxn];
void dfs(int sx, int sy) {
    vis[sx][sy] = true;
    for (int i = 0; i < 4; i++) {
        int tx = sx + dir[i][0], ty = sy + dir[i][1];
        if (tx > n || ty > m || tx < 1 || ty < 1 || mp[tx][ty] == '#' || vis[tx][ty])
            continue;
        dfs(tx, ty);
    }
}
int main() {
    for (int i = 1; i <= 10; i++) {
        string in = to_string(i) + ".in";
        string out = to_string(i) + ".out";
        freopen(in.c_str(), "r", stdin);
        freopen(out.c_str(), "w", stdout);
        cin >> n >> m;
        memset(vis, 0, sizeof vis);
        int sx, sy;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j] && mp[i][j] != '#')
                    ans++, dfs(i, j);
            }
        }
        cout << ans << endl;
        ans = 0;
        cin.clear();
    }
    return 0;
}