#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
typedef long double db;
db ans[3000][3000];
int vs[3000][3000];
db dfs(int n, int m) {
    if (vs[n][m])
        return ans[n][m];
    db p = 1 - (db)m / (m + 1) * dfs(m - 1, n) - (db)1 / (m + 1);
    return vs[n][m] = 1, ans[n][m] = max((db)1 / (m + 1), p);
}
void sol(int TestCase) {
    int n, m;
    cin >> n >> m;
    cout << ans[n][m] << '\n';
}
void init() {
    for (int i = 0; i <= 2000; i++)
        ans[0][i] = (db)1 / (i + 1), vs[0][i] = 1;
    for (int i = 0; i <= 2000; i++)
        ans[i][0] = 1, vs[i][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            ans[i][j] = dfs(i, j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int T = 1, TestCase = 0;
    cin >> T;
    for (init(); T--;)
        sol(++TestCase);
    return 0;
}