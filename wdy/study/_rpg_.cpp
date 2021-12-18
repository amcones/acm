/***********************************
// @Author   :   amcones
// @Problem  :   _rpg_.cpp
// @When     :   2021-12-08 21:27:52
***********************************/
#include <algorithm>
#include <cctype>
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
const int maxn = 1e2 + 10;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int n, m, h;
struct lq {
    int x, y, h;
    lq(int x, int y, int h)
        : x(x), y(y), h(h) {}
};
vector<lq> a;
int main() {
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (isdigit(mp[i][j]))
                a.push_back(lq(i, j, mp[i][j] - '0'));
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 1 << a.size(); i++) {  //二进制枚举每一个位置是否取
        int sum = 0;
        for (int j = 0; j < a.size(); j++) {
            if ((1 << j) & i)  //取当前这位
                vis[a[j].x][a[j].y] = 1, sum += a[j].h;
            else
                vis[a[j].x][a[j].y] = 0;
        }
        if (sum >= h)  //总受伤超过血量就不行
            continue;
        //满足血量再bfs
        queue<PII> q;
        q.push({1, 1});
        int st[maxn][maxn];
        memset(st, -1, sizeof st);
        st[1][1] = 0;
        while (!q.empty()) {
            PII t = q.front();
            q.pop();
            for (auto j : dir) {
                int tx = t.first + j[0], ty = t.second + j[1];
                if (tx < 1 || tx > n || ty < 1 || ty > m || st[tx][ty] != -1)
                    continue;
                if (mp[tx][ty] == '.' || (mp[tx][ty] != '*' && vis[tx][ty])) {
                    st[tx][ty] = st[t.first][t.second] + 1;
                    q.push({tx, ty});
                }
            }
        }
        if (st[n][m] != -1)
            ans = min(ans, st[n][m]);
    }
    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}