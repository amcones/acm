// Created on James的iPad.

#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
long long x, k;
int ans[maxn];
int p;
void solve(long long n) {
    if (n) {
        ans[p++] = n % k;
        solve(n / k);
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        string in = to_string(i) + ".in";
        string out = to_string(i) + ".out";
        freopen(in.c_str(), "r", stdin);
        freopen(out.c_str(), "w", stdout);
        cin >> x >> k;
        p = 0;
        solve(x);
        for (int i = p - 1; i >= 0; i--)
            cout << ans[i];
        cin.clear();
    }
    return 0;
}