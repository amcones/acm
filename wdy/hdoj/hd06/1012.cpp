/***********************************
// @Author   :   amcones
// @Problem  :   1012.cpp
// @When     :   2022-08-04 13:08:05
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
const int maxn = 3e5 + 10;

int tree[maxn];
int n, k;

inline int lowbit(int x) {
    return (x & -x);
}
inline void update(int i, int x) {
    while (i <= n)
        tree[i] += x, i += lowbit(i);
}
inline int query(int x) {
    int ans = 0;
    while (x) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
inline int query(int a, int b) {
    return query(b) - query(a - 1);
}

int a;
int tr[maxn << 1];
int ans[maxn];
vector<int> pos[maxn];

void init() {
    memset(tree, 0, sizeof tree);
    for (int i = 1; i <= maxn; i++)
        vector<int>().swap(pos[i]);
    memset(ans, 0, sizeof ans);
}
void solve() {
    cin >> n >> k;
    int maxa = 0;
    for (int i = 1; i <= n; i++)
        cin >> a, maxa = max(a, maxa), pos[a].push_back(i);
    //从大到小，把每个数挪到指定位置
    for (int i = maxa; i >= 1; i--) {
        if (pos[i].empty())
            continue;
        for (auto l : pos[i]) {
            l = max(1, l - k);
            int r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (query(mid) < mid)
                    r = mid;
                else
                    l = mid + 1;
            }
            update(r, 1);
            ans[r] = i;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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