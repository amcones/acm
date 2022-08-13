#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct FT {
    vector<ll> s;
    FT(int n)
        : s(n) {}
    void update(int pos, ll dif) {
        for (; pos < (int)s.size(); pos |= pos + 1)
            s[pos] += dif;
    }
    ll query(int pos) {
        // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1)
            res += s[pos - 1];
        return res;
    }
    int lower_bound(ll sum) {
        // min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0)
            return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= (int)s.size() && s[pos + pw - 1] < sum)
                pos += pw, sum -= s[pos - 1];
        }
        return pos;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    FT fenwick(n);
    for (int i = 0; i < n; i++)
        fenwick.update(i, 1);
    vector<array<int, 2>> ops(n);
    for (auto& [p, v] : ops)
        cin >> p >> v;
    reverse(ops.begin(), ops.end());
    vector<int> ans(n);
    for (auto& [p, v] : ops) {
        int it = fenwick.lower_bound(p + 1);
        fenwick.update(it, -1), ans[it] = v;
    }
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}