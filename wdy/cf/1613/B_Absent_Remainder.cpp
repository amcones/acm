/***********************************
// @Author   :   amcones
// @Problem  :   B_Absent_Remainder.cpp
// @When     :   2021-12-01 23:03:41
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
const int maxn = 2e5 + 10;
const int maxm = 1e6 + 10;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 2; i - 1 <= n / 2; i++) {
            cout << a[i] << ' ' << a[1] << endl;
        }
    }
    return 0;
}