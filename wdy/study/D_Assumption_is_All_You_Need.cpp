/***********************************
// @Author   :   amcones
// @Problem  :   D_Assumption_is_All_You_Need.cpp
// @When     :   2021-11-17 23:53:02
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
const int maxn = 3000;
int a[maxn], b[maxn];
int pa[maxn], pb[maxn];
void solve() {
    vector<PII> ans;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pa[a[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i], pb[b[i]] = i;
    for (int i = 1; i <= n; i++) {
        if (pa[i] == pb[i])
            continue;
        if (pa[i] < pb[i]) {
            cout << "-1\n";
            return;
        }
        int nowl = pb[i], nowr = pa[i];
        for (int j = i + 1; j <= n; j++)
            if (pa[j] >= nowl && pa[j] <= nowr) {
                ans.push_back({pa[j], nowr});
                swap(a[pa[j]], a[nowr]);
                swap(pa[j], nowr);
            }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i]) {
            cout << "-1\n";
            return;
        }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x.first << ' ' << x.second << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}