/***********************************
// @Author   :   amcones
// @Problem  :   2021JinanicpcD.cpp
// @When     :   2021-11-15 22:34:23
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
ll a[maxn], dif[maxn], c[maxn];
int n;
__int128_t check(ll d) {
    c[0] = 0;
    for (int i = 1; i < n; i++) {
        c[i] = c[i - 1] + d - dif[i + 1];
    }
    nth_element(c, c + n / 2, c + n);
    __int128_t x = c[n / 2];
    __int128_t res = 0;
    for (int i = 0; i < n; i++) {
        __int128_t y = x - c[i];
        if (y > 0)
            res += y;
        else
            res += -y;
    }
    return res;
}
void print(__int128_t x) {
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dif[i] = a[i] - a[i - 1];
    }
    ll l = -1e13, r = 1e13;
    while (l + 1 < r) {
        ll lmid = l + (r - l >> 1), rmid = lmid + (r - lmid >> 1);
        if (check(lmid) > check(rmid))
            l = lmid;
        else
            r = rmid;
    }
    print(check(r));
    return 0;
}