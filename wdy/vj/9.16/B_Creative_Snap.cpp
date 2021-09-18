#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
ll a[maxn];
int n, k, A, B;
ll solve(ll l, ll r)
{
    ll mid = l + r >> 1, ans;
    int num = upper_bound(a + 1, a + 1 + k, r) - lower_bound(a + 1, a + 1 + k, l);
    if (num == 0)
        ans = A;
    else {
        ans = B * num * (r - l + 1);
        if (r - l >= 1)
            ans = min(ans, solve(l, mid) + solve(mid + 1, r));
    }
    return ans;
}
int main()
{
    cin >> n >> k >> A >> B;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + k);
    cout << solve(1, 1 << n) << endl;
    return 0;
}