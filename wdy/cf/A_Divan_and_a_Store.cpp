/***********************************
// @Author   :   amcones
// @Problem  :   A_Divan_and_a_Store.cpp
// @When     :   2021-12-03 18:05:16
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
int a[200];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= l && a[i] <= r) {
                if (k - a[i] >= 0)
                    k -= a[i], ans++;
                else
                    break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}