/***********************************
// @Author   :   amcones
// @Problem  :   C_Di_visible_Confusion.cpp
// @When     :   2021-10-30 23:51:26
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
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool ans = true;
        for (int i = 1; i <= n; i++) {
            bool f = false;
            for (int j = i; j >= 1; j--) {
                if (a[i] % (j + 1) != 0) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                cout << "NO\n", ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
    }
    return 0;
}