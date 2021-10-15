/***********************************
// @Author   :   amcones
// @Version  :   1.0
// @Problem  :   acw1098.cpp
// @When     :   2021-10-11 17:20:25
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
const int maxn = 1e5 + 10;
int g[100][100];
bool st[100][100];
int m, n;
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
//在遍历方向的时候，墙的方向是固定的，所以方向也必须固定。
int bfs(int sx, int sy) {
    int area = 0;
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = 1;
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        area++;
        for (int i = 0; i < 4; i++) {
            int tx = t.first + dir[i][0], ty = t.second + dir[i][1];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n)
                continue;
            if (!st[tx][ty] && !(g[t.first][t.second] >> i & 1)) {
                q.push({tx, ty});
                st[tx][ty] = 1;
            }
        }
    }
    return area;
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    int cnt = 0, area = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!st[i][j])
                area = max(area, bfs(i, j)), cnt++;
    cout << cnt << endl;
    cout << area << endl;
    return 0;
}