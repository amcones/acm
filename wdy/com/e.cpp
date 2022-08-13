#include <bits/stdc++.h>
using namespace std;
int dis[55][55], tmp[55][55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(dis, 0x3f, sizeof dis);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    const int inf = 0x3f3f3f3f;
    int ans = 0;
    for (int del = 2; del < n; del++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == del || j == del)
                    tmp[i][j] = inf;
                else
                    tmp[i][j] = dis[i][j];
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    tmp[i][j] = min(tmp[i][j], tmp[i][k] + tmp[k][j]);
                }
            }
        }
        ans = max(ans, tmp[1][n]);
    }
    if (ans >= inf)
        cout << "inf";
    else
        cout << ans;
    return 0;
}