/***********************************
// @Author   :   amcones
// @Problem  :   B_Triangles_on_a_Rectangle.cpp
// @When     :   2021-12-19 00:02:41
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
const int maxn = 2e5 + 10;
ll p[4][maxn];
ll len[4];
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll w, h;
        cin >> w >> h;
        for (int i = 0; i < 4; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                cin >> p[i][j];
            }
            len[i] = p[i][k] - p[i][1];
        }
        cout << max({len[0] * h, len[1] * h, len[2] * w, len[3] * w}) << endl;
    }
    return 0;
}