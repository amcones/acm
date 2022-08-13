#include <bits/stdc++.h>
#define ull unsigned long long
#define ll __int128
using namespace std;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll n;
ll a[100010];
int b[20];
inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    //    ios::sync_with_stdio(0);
    //    cin.tie(0);cout.tie(0);

    n = read();
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum += a[i];
        for (int j = 0; j <= 16; j++) {
            if ((a[i] >> j) & 1)
                b[j]++;
        }
    }
    ll q = gcd(sum, n);
    ll x0 = sum / q;
    ll y0 = n / q;
    // cout<<x0<<" "<<y0<<"\n";

    ll s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        ll x = 0;
        for (int j = 16; j >= 0; j--) {
            if (b[j]) {
                b[j]--;
                x = x + (1 << j);
            }
        }
        // cout<<x<<"\n";
        s1 = s1 + (x * y0 - x0) * (x * y0 - x0);
    }
    s2 = y0 * n * y0;
    q = gcd(s1, s2);
    // cout<<s1<<" "<<s2<<"\n";
    s1 = s1 / q;
    s2 = s2 / q;
    print(s1);
    cout << "/";
    print(s2);
    cout << "\n";

    return 0;
}