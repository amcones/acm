#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;

int main() {
    ll x, y, m;
    cin >> x >> y >> m;
    if (x < y)
        swap(x, y);
    if (x >= m)
        return cout << 0 << endl, 0;
    if (x <= 0)
        return cout << -1 << endl, 0;
    ll ans = abs(y) % x ? abs(y) / x + 1 : abs(y) / x;
    y += ans * x;
    if (x < y)
        swap(x, y);
    while (x < m) {
        y += x;
        if (y > x)
            swap(x, y);
        ans++;
    }
    cout << ans << endl;
    return 0;
}