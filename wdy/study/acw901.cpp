#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 4e2 + 10;
const int mod = 1e9 + 7;
int mp[maxn][maxn];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int dp[maxn][maxn];
int r, c;
int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    for (int i = 0; i < 4; i++)
    {
        int sx = x + dir[i][0], sy = y + dir[i][1];
        if (sx > 0 && sy > 0 && sx <= r && sy <= c && mp[sx][sy] < mp[x][y])
        {
            dp[x][y] = max(dp[x][y], dfs(sx, sy) + 1);
        }
    }
    return dp[x][y];
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans + 1 << endl;
    return 0;
}