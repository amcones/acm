#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
char mp[20][20];
int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy, ox, oy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '#')
                sx = i, sy = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '*') {
                int tmp = 0;
                tmp += (mp[i + 1][j] == '*' || mp[i - 1][j] == '*');
                tmp += (mp[i][j - 1] == '*' || mp[i][j + 1] == '*');
                if (tmp >= 2) {
                    ox = i, oy = j;
                    break;
                }
            }
        }
    }
    cout << sy - oy << ' ' << ox - sx << endl;
    return 0;
}