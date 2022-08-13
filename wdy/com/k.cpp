#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n;
int dp[20000 + 200];
signed main() {
    scanf("%d", &n);
    int ans = -inf, sum = 0;
    dp[10000] = 1;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        sum += x;
        if (x > 0)
            for (int j = 2e4; j >= max(0, x); j--)
                dp[j] |= dp[j - x];
        else
            for (int j = 0; j <= 2e4; j++)
                dp[j] |= dp[j - x];
    }
    for (int j = 0; j <= 2e4; j++) {
        if (dp[j]) {
            ans = max(ans, (j - 10000) * (sum - (j - 10000)));
        }
    }
    printf("%d\n", ans);
    return 0;
}