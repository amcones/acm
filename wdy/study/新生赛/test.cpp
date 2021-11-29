#include <cstring>
#include <iostream>
#include <queue>
#define ll long long
using namespace std;
const int maxn = 1e3 + 7;
const int inf = 0x3f3f3f;
const int mod = 1e9 + 7;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
int n, m, cnt;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct node {
    int x, y;
    node(int _x, int _y) {
        x = _x;
        y = _y;
    }
};
int bfs(int x, int y) {
    queue<node> q;
    q.push(node(x, y));
    while (!q.empty()) {
        node e = q.front();
        if (maze[e.x][e.y] == 'G')
            cnt++;
        q.pop();
        if (e.x == 0 || e.x == n + 1 || e.y == 0 || e.y == m + 1)
            return dis[e.x][e.y];
        for (int i = 0; i < 4; i++) {
            int sx = e.x + dx[i];
            int sy = e.y + dy[i];
            if (!vis[sx][sy] && maze[sx][sy] != '#') {
                q.push(node(sx, sy));
                vis[sx][sy] = 1;
                dis[sx][sy] = dis[e.x][e.y] + 1;
            }
        }
    }
    return -1;
}
int main() {
    freopen("1.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> maze[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == 'U') {
                vis[i][j] = 1;
                int ans = bfs(i, j);
                if (ans != -1) {
                    printf("%d %d\n", ans, cnt);
                } else
                    puts("-1");
                return 0;
            }
        }
    }
    return 0;
}