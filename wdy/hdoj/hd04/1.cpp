#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    int k = 0;
    for (int i = 62; i >= 0; i--) {
        for (int j = k; j < n; j++)
            if (a[j] >> i & 1) {
                swap(a[j], a[k]);
                break;
            }
        if (!(a[k] >> i & 1))
            continue;
        for (int j = 0; j < n; j++)
            if (j != k && (a[j] >> i & 1))
                a[j] ^= a[k];
        k++;
        if (k == n)
            break;
    }

    LL res = 0;
    for (int i = 0; i < k; i++)
        res ^= a[i];
    printf("%lld\n", res);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}