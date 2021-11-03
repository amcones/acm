/***********************************
// @Author   :   amcones
// @Problem  :   acw890.cpp
// @When     :   2021-10-30 14:02:00
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
int p[20];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];
    int res = 0;
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, s = 0;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                if (1ll*t * p[j] > n) {
                    t = -1;
                    break;
                }
                s++;
                t *= p[j];
            }
        }
        if (t == -1)
            continue;
        if (s & 1)
            res += n / t;
        else
            res -= n / t;
    }
    cout << res << endl;
    return 0;
}