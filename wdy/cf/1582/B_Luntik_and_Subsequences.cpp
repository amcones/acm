/***********************************
// @Author   :   amcones
// @Problem  :   B_Luntik_and_Subsequences.cpp
// @When     :   2021-10-24 18:37:52
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
const int maxn = 1e2 + 10;
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, n1 = 0, n2 = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a == 0)
                n1++;
            else if (a == 1)
                n2++;
        }
        ll ans = power(2, n1);
        cout << n2 * ans << endl;
    }
    return 0;
}