/***********************************
// @Author   :   amcones
// @Problem  :   B_XOR_Specia_LIS_t.cpp
// @When     :   2021-10-30 22:52:49
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
vector<int> a(maxn);
map<int, int> mp;
int main() {
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n % 2 == 0) {
            cout << "YES\n";
            continue;
        }
        bool f = false;
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] >= a[i]) {
                cout << "YES\n";
                f = true;
                break;
            }
        }
        if (!f)
            cout << "NO\n";
    }
    return 0;
}