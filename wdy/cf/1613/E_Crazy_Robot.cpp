/***********************************
// @Author   :   amcones
// @Problem  :   E_Crazy_Robot.cpp
// @When     :   2021-12-01 23:37:42
***********************************/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e6 + 10;
string mp[maxn];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
void bfs(int sx, int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        PII t = q.front();
        q.pop();
        for (auto &i : dir)
        {
            int tx = t.first + i[0], ty = t.second + i[1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || mp[tx][ty] != '.')
                continue;
            int all = 0, good = 0;
            for (auto &j : dir)
            {
                int ux = tx + j[0], uy = ty + j[1];
                if (ux < 0 || ux >= n || uy < 0 || uy >= m || mp[ux][uy] == '#')
                    continue;
                ++all;
                if (mp[ux][uy] != '.')
                    ++good;
            }
            if (good && all - good <= 1)
                mp[tx][ty] = '+', q.push({tx, ty});
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int sx, sy;
        for (int i = 0; i < n; i++)
            cin >> mp[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] == 'L')
                    sx = i, sy = j;
        bfs(sx, sy);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%c", mp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}