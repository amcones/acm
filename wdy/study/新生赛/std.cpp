/***********************************
// @Author   :   amcones
// @Problem  :   uli的迷宫.cpp
// @When     :   2021-11-22 10:20:51
***********************************/
#include <assert.h>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 6e2 + 10;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int step[maxn][maxn];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
int S = 0x3f3f3f3f, Y = 0;
void bfs(PII r) {
    queue<PII> q;
    q.push(r);
    vis[r.first][r.second] = true;
    bool f = false;
    while (!q.empty()) {
        PII s = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = s.first + dir[i][0], ty = s.second + dir[i][1];
            if (mp[tx][ty] == '#' || vis[tx][ty])
                continue;
            vis[tx][ty] = true;
            step[tx][ty] = step[s.first][s.second] + 1;
            if (f && step[tx][ty] > S)
                continue;
            if (mp[tx][ty] == 'G')
                Y++;
            if (tx < 1 || tx > n || ty < 1 || ty > m) {
                if (!f) {
                    S = step[tx][ty];
                    f = true;
                }
                continue;
            }
            q.push({tx, ty});
        }
    }
}
int main() {
    for (int i = 1; i <= 100; i++) {
        char chtempin[100], chtempout[100];
        sprintf(chtempin, "%d%s", i, ".in");
        sprintf(chtempout, "%d%s", i, ".out");
        freopen(chtempin, "r", stdin);
        freopen(chtempout, "w", stdout);
        S = 0x3f3f3f3f, Y = 0;
        memset(vis, 0, sizeof vis);
        memset(mp, 0, sizeof mp);
        cin >> n >> m;
        int sx, sy;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == 'U')
                    sx = i, sy = j;
            }
        // assert(!(sx > 500 || sy > 500 || sx < 0 || sy < 0));
        step[sx][sy] = 0;
        memset(step, 0, sizeof step);
        bfs({sx, sy});
        if (S != 0x3f3f3f3f)
            cout << S << ' ' << Y << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}