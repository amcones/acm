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
ll a[maxn];
int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans += a[i];
    cout << ans * (n - 1);
    return 0;
}