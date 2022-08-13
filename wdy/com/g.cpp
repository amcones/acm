#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int Test;
    cin >> Test;
    while (Test--) {
        int n, m, k;
        cin >> n >> m >> k;
        m -= n;
        auto check = [&](int x) -> bool {
            long long ls = min(k - 1, x - 1);
            ls = 1LL * (x - 1 + x - ls) * ls / 2;
            long long rs = min(n - k, x - 1);
            rs = 1LL * (x - 1 + x - rs) * rs / 2;
            return ls + rs + x <= m;
        };
        int l = 1, r = m, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << 1 + ans << '\n';
    }
    return 0;
}