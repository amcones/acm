/***********************************
// @Author   :   amcones
// @Problem  :   cf1623A.cpp
// @When     :   2021-12-29 17:35:56
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;
        cout << min(r1 <= r2 ? r2 - r1 : 2 * n - r1 - r2, c1 <= c2 ? c2 - c1 : 2 * m - c1 - c2) << endl;
    }
    return 0;
}