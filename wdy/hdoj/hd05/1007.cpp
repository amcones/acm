/***********************************
// @Author   :   amcones
// @Problem  :   1007.cpp
// @When     :   2022-08-02 12:23:54
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
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 5e5 + 10;
const int mod = 998244353;
ll fact[maxn];
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll inv(ll a, ll p) {
    ll x, y;
    if (exgcd(a, p, x, y) != 1)
        return -1;
    return (x % p + p) % p;
}
ll C(ll m, ll n, ll p) {
    return m < n ? 0 : fact[m] * inv(fact[n], p) % p * inv(fact[m - n], p) % p;
}
void init() {
}
void solve() {
    int n, k;
    cin >> n >> k;
    ll cnt = 0;
    ll p;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        if (p != i)
            cnt++;
    }
    cout << C(cnt, k, mod) << endl;
}
int main() {
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}