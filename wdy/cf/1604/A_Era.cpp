/***********************************
// @Author   :   amcones
// @Problem  :   A_Era.cpp
// @When     :   2021-10-30 22:44:30
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
int a[150];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > i)
                ans = max(ans, a[i] - i);
        }
        cout << ans << endl;
    }
    return 0;
}