/***********************************
// @Author   :   amcones
// @Problem  :   acw1106.cpp
// @When     :   2021-10-12 16:50:21
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
const int N = 1e4 + 10;
int n;
bool st[N][N];
int g[N][N];
void bfs(int sx, int sy, bool& hi, bool& lo) {
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        for (int i = t.first - 1; i <= t.first + 1; i++)
            for (int j = t.second - 1; j <= t.second + 1; j++) {
                if (i == t.first && j == t.second)
                    continue;
                if (i < 0 || i >= n || j < 0 || j >= n)
                    continue;
                if (g[i][j] != g[t.first][t.second]) {
                    if (g[i][j] > g[t.first][t.second])
                        hi = true;
                    else if (g[i][j] < g[t.first][t.second])
                        lo = true;
                } else if (!st[i][j]) {
                    q.push({i, j}), st[i][j] = true;
                }
            }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (!st[i][j]) {
                bool hi = false, lo = false;
                bfs(i, j, hi, lo);
                if (!hi)
                    peak++;
                if (!lo)
                    valley++;
            }
        }
    cout << peak << ' ' << valley;
    return 0;
}