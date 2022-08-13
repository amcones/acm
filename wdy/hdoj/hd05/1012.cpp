/***********************************
// @Author   :   amcones
// @Problem  :   1012.cpp
// @When     :   2022-08-02 12:49:27
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
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 2e5 + 10;
vector<PII> vec;
priority_queue<PII> q;
void init() {
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, s;
        cin >> a >> s;
        vec.push_back({a, s});
    }
    sort(vec.begin(), vec.end(), [](const PII& a, const PII& b) {
        return a.first < b.first;
    });
    for (int i = 1; i <= m; i++)
        q.push({0, 0});
    for (auto i : vec) {  //把人放进来
        while (q.top().second <= i.first) {
            auto [num, last] = q.top();
            q.pop();
            if (num > 0)
                num--;
            q.push({num, last});
        }
        auto [num, last] = q.top();
        q.pop();
        num++, last = last + i.second;
        q.push({num, last});
    }
    int ans = 0;
    while (!q.empty()) {
        ans = max(ans, q.top().second);
        q.pop();
    }
    cout << ans << endl;
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}