/***********************************
// @Author   :   amcones
// @Problem  :   C_Fault-tolerant_Network.cpp
// @When     :   2022-07-31 10:24:04
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

//如何满足删除一个节点仍联通
//假如在第一行删去一个节点，第一行会被分成两部分，两部分需要分别有边连接第二行
//可以选择在两边放两条边，或者在中间放四条边
// A1 BestA An
// B1 BestB Bn
//先把A1 An连到对面，如果B1没有连就加一条，Bn没有连就加一条

int bestCal(const vector<ll>& vec, int cur) {
    int pos = 1;
    ll ans = 0x7fffffff;
    for (int i = 1; i < vec.size(); i++) {
        if (abs(vec[i] - cur) < ans)
            pos = i, ans = abs(vec[i] - cur);
    }
    return pos;
}

void init() {
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<ll> tmp = {b[1], b[n], b[bestCal(b, a[1])]};
    ll lastans = 0;
    ll ans = 0x7fffffff, pos = 0;
    bool b1 = false, b2 = false;
    for (int i = 0; i < 3; i++) {
        if (abs(a[1] - tmp[i]) < ans) {
            ans = abs(a[1] - tmp[i]);
            pos = i;
        }
    }
    if (pos == 0)
        b1 = true;
    else if (pos == 1)
        b2 = true;
    lastans += ans;
    ans = 0x7ffffffff;
    pos = 0;
    tmp = {b[1], b[n], b[bestCal(b, a[n])]};
    for (int i = 0; i < 3; i++) {
        if (abs(a[n] - tmp[i]) < ans) {
            ans = abs(a[n] - tmp[i]);
            pos = i;
        }
    }
    if (pos == 0)
        b1 = true;
    else if (pos == 1)
        b2 = true;
    lastans += ans;
    if (!b1) {
        lastans += abs(a[bestCal(a, b[1])] - b[1]);
    }
    if (!b2) {
        lastans += abs(a[bestCal(a, b[n])] - b[n]);
    }
    cout << lastans << endl;
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