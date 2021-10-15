/***********************************
// @Author   :   amcones
// @Version  :   1.0
// @Problem  :   acw175.cpp
// @When     :   2021-10-09 20:55:16
***********************************/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e3 + 10;
int n, m;
char g[maxn][maxn];
bool st[maxn][maxn];
int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};
void bfs(int sx, int sy) {
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;
    while (!q.empty()) {
        PII p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tx = p.first + dir[i][0], ty = p.second + dir[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                continue;
            if (!st[tx][ty] && g[tx][ty] == 'W')
                q.push({tx, ty}), st[tx][ty] = true;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}