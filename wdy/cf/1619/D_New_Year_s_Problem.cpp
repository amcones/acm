/***********************************
// @Author   :   amcones
// @Problem  :   D_New_Year_s_Problem.cpp
// @When     :   2021-12-21 11:56:28
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
bool check(int mid, vector<vector<int>> p, int n, int m) {
    int i, j;
    for (auto& v : p)
        for (auto& x : v)
            x = x >= mid;
    vector<int> tot(m);
    for (auto v : p)
        for (i = 0; i < m; i++)
            tot[i] += v[i];
    if (*min_element(tot.begin(), tot.end()) == 0)
        return 0;
    for (i = 0; i < n; i++)
        if (accumulate(p[i].begin(), p[i].end(), 0) > 1)
            return 1;
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l = 0, r = 1e9, mid;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> p(n);
        for (auto& v : p) {
            v.resize(m);
            for (auto& x : v)
                cin >> x;
        }
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (check(mid, p, n, m))
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}