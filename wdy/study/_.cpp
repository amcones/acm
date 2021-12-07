/***********************************
// @Author   :   amcones
// @Problem  :   _.cpp
// @When     :   2021-12-04 20:52:40
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
const int maxn = 1e5 + 10;
#define X 0x3f3f3f3f
using namespace std;

int Min[100][100];
char State[100][100];
bool vis[100][100];
int n, m, h;
int i, j, k;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
void bfs(int sx, int sy) {
    queue<PII> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    Min[sx][sy] = 0;
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = dir[i][0] + t.first, ty = dir[i][1] + t.second;
            if (tx < 0 || tx > n || ty < 0 || ty > m || vis[tx][ty] || State[tx][ty] == '*')
                continue;
            vis[tx][ty] = true;
            Min[tx][ty] = Min[t.first][t.second] + 1;
            q.push({tx, ty});
        }
    }
}
int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> State[i][j];
        }
    }
    //先将每个点的长度置为无穷（X）
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            Min[i][j] = X;
        }
    }
    bfs(0, 0);
    // init

    //搜索图，并记录最小长度
    for (int k = 0; k < 100; k++) {
        for (int j = 0; j < 100; j++) {
            for (int i = 0; i < 100; i++) {
                Min[k][j] = min(Min[k][j], Min[k][i] + Min[i][j]);  //目前比较有疑问的是他的状态方程为什么写成这样
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (i = 1; i < 100; i++) {
        ans = min(ans, Min[0][i]);
    }
    cout << ans << endl;
    return 0;
}
