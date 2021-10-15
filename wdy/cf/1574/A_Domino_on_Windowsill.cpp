#include <bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
inline ll read()
{
    char ch;
    ll f = 1;
    while ((ch = getchar()) < '0' || ch > '9')
        if (ch == '-')
            f = -1;
    ll res = ch - 48;
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - 48;
    return res * f;
}
ll n, k1, k2, w, b, k3, k4, ans1, ans2;
int main()
{
    ll t = read();
    while (t--) {
        n = read(), k1 = read(), k2 = read();
        w = read(), b = read();
        if (k1 < k2)
            swap(k1, k2);
        k3 = n - k2, k4 = n - k1;
        ans1 = k2 + (k1 - k2) / 2;
        ans2 = k4 + (k3 - k4) / 2;
        if (w <= ans1 && b <= ans2)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}