/***********************************
// @Author   :   amcones
// @Problem  :   D_Vupsen_Pupsen_and_0.cpp
// @When     :   2021-10-24 19:42:27
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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll a[maxn], b[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n % 2 == 0) {
            for (int i = 1; i <= n - 1; i += 2) {
                cout << a[i + 1] * (-1) << ' ' << a[i] << ' ';
            }
            cout << endl;
        } else {
            for (int i = 1; i <= n - 3; i += 2) {
                b[i] = a[i + 1] * (-1), b[i + 1] = a[i];
            }
            ll tmp = lcm(lcm(a[n - 2], a[n - 1]), a[n]);
            b[n - 2] = tmp / a[n - 2], b[n - 1] = -tmp * 2 / a[n - 1], b[n] = tmp / a[n];
            for (int i = 1; i <= n; i++)
                cout << b[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}