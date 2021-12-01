/***********************************
// @Author   :   amcones
// @Problem  :   H_Pushing_Robots.cpp
// @When     :   2021-11-28 22:35:52
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
ll a[20];
ll b[20];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll sum = 0;
            memcpy(b, a, sizeof(a));
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                while (b[j] % 2 == 0) {
                    b[i] *= 2, b[j] /= 2;
                }
            }
            for (int j = 1; j <= n; j++)
                sum += b[j];
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}