#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5, mod = 998244353;
int n;
int a[maxn];
int cnt[5010];
ll qpow(ll a, ll b) {
    ll ans = 1, base = a;
    while (b) {
        if (b & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    ll ans = 1;
    for (int i = 0; i <= 5e3; i++) {
        for (int j = i; j <= 5e3; j++) {
            if (i == j) {
                ans = ans * qpow(i + j, (1ll * cnt[i] * (cnt[i] - 1) / 2 % (mod - 1))) % mod;
            } else {
                ans = ans * qpow(i + j, 1ll * cnt[i] * cnt[j] % (mod - 1)) % mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}