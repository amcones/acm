/***********************************
// @Author   :   amcones
// @Problem  :   B_Build_the_Permutation.cpp
// @When     :   2021-12-11 18:34:06
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
int ans[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (abs(a - b) > 1 || (n % 2 == 0 && (a > n / 2 - 1 || b > n / 2 - 1)) || (n % 2 == 1 && (a > n / 2 || b > n / 2 || a == n / 2 && b == n / 2))) {
            cout << -1 << endl;
            continue;
        }
        if (a > b) {
            for (int i = 1; i <= n; i++) {
                ans[i] = i;
            }
            for (int i = 2; i < n; i += 2) {
                if (a && b)
                    swap(ans[i], ans[i + 1]), a--, b--;
                else
                    break;
            }
            swap(ans[n - 1], ans[n]);
        } else {
            for (int i = 1; i <= n; i++) {
                ans[i] = n - i + 1;
            }
            for (int i = 2; i < n; i += 2) {
                if (a && b)
                    swap(ans[i], ans[i + 1]), a--, b--;
                else
                    break;
            }
            if (b)
                swap(ans[n - 1], ans[n]);
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}