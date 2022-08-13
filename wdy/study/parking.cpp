/***********************************
// @Author   :   amcones
// @Problem  :   parking.cpp
// @When     :   2021-12-23 19:51:24
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
using PIII = pair<int, PII>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
double car[maxn];
struct node {
    double x, s1, s2;
    int st;
    bool operator<(const node a) const {
        return x < a.x;
    }
};
double ans = 20;
int n;
void bfs(int s) {
    priority_queue<node> q;
    double s1 = 0, s2 = 0;
    q.push({max(s1, s2), s1, s2, s});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        s = t.st;
        if (t.x > ans || t.x > 15)
            continue;
        if (t.st == n) {
            ans = min(ans, t.x);
            continue;
        }
        node d1, d2;
        s++;
        if (s > n)
            continue;
        d1 = {max(t.s1 + car[s], t.s2), t.s1 + car[s], t.s2, s};
        d2 = {max(t.s1, t.s2 + car[s]), t.s1, t.s2 + car[s], s};
        q.push(d1), q.push(d2);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> car[i];
    }
    bfs(0);
    cout << ans << endl;
    return 0;
}