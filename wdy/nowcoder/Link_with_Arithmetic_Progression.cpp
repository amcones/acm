/***********************************
// @Author   :   amcones
// @Problem  :   Link_with_Arithmetic_Progression.cpp
// @When     :   2022-07-25 10:38:05
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
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
using ld = long double;

pair<ld, ld> LeastSquares(const vector<ld>& X, const vector<ld>& Y) {
    int vec_size = X.size();
    ld sum1 = 0, sum2 = 0;
    ld x_avg = std::accumulate(X.begin(), X.end(), 0.0L) / vec_size;
    ld y_avg = std::accumulate(Y.begin(), Y.end(), 0.0L) / vec_size;

    for (int i = 0; i < vec_size; ++i) {
        sum1 += (X.at(i) * Y.at(i) - x_avg * y_avg);
        sum2 += (X.at(i) * X.at(i) - x_avg * x_avg);
    }

    ld k = sum1 / sum2;
    ld b = y_avg - k * x_avg;
    return {k, b};
}
//更改每一项的值使得原数列变为算术级数并且代价最小
void init() {
}
void solve() {
    int n;
    cin >> n;
    vector<ld> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> Y[i], X[i] = i;
    }
    auto [k, b] = LeastSquares(X, Y);
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ans += pow(Y[i] - k * X[i] - b, 2);
    }
    cout << fixed << setprecision(8) << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}