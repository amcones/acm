/***********************************
// @Author   :   amcones
// @Version  :   1.0
// @Problem  :   B_Too_Many_Segments_easy_version_.cpp
// @When     :   2021-10-11 20:15:59
***********************************/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<PII, int>;
using PLL = pair<ll, ll>;
const int maxn = 2e5 + 10;
//贪心，从前往后找，删掉覆盖点最靠后的线段，因为它覆盖的点最多。
PIII a[maxn];
vector<int> ans;
set<PII> st;
int main() {
    int n, k, l, r;
    PII t;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        l = min(l, a[i].first.first), r = max(r, a[i].first.second);
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, [](PIII a, PIII b) {
        return a.first.first < b.first.first;
    });
    //对每个点考虑
    int p = 1;
    for (int i = l; i <= r; i++) {
        while (p <= n && a[p].first.first <= i) {
            st.insert({a[p].first.second, a[p].second});
            p++;
        }
        while (st.size() && st.begin()->first < i)
            st.erase(st.begin());
        while (st.size() > k) {
            t = *(--st.end());
            ans.push_back(t.second);
            st.erase(t);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}