#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
ll a[maxn];
int main()
{
    ll n, t;
    cin >> n >> t;
    ll sum = 0;
    ll m = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        m = min(m, a[i]);
    }
    ll ans = 0, num = n;
    while (t >= m) {
        if (t >= sum) {
            ans += (t / sum) * num;
            t %= sum;
        } else {
            sum = 0, num = 0;
            for (int i = 1; i <= n && t >= m; i++) {
                if (t >= a[i]) {
                    t -= a[i], sum += a[i];
                    num++, ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}