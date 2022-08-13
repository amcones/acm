#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct ZYYS {
    double l, r;
} a[5001];
double pi = acos(-1.0);
int n;
double x[1001], y[1001], r[1001], ans;
bool cmp(ZYYS a, ZYYS b) {
    return a.l < b.l;
}
double dist(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
bool contain(int i, int j) {
    if (r[i] - r[j] >= dist(i, j))
        return 1;
    return 0;
}
double cal(int o) {
    int i;
    int cnt = 0;
    for (i = o + 1; i <= n; i++)
        if (contain(i, o))
            return 0;
    for (i = o + 1; i <= n; i++) {
        if (contain(o, i) || dist(o, i) >= r[i] + r[o])
            continue;
        double d = dist(o, i);
        double xt = acos((-r[i] * r[i] + r[o] * r[o] + d * d) / (2.0 * d * r[o]));
        double aef = atan2(y[i] - y[o], x[i] - x[o]);
        a[++cnt] = (ZYYS){aef - xt, aef + xt};
        if (a[cnt].l < 0)
            a[cnt].l += 2 * pi;
        if (a[cnt].r < 0)
            a[cnt].r += 2 * pi;
        if (a[cnt].l > a[cnt].r) {
            double p = a[cnt].l;
            a[cnt].l = 0;
            a[++cnt].l = p;
            a[cnt].r = 2 * pi;
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    double res = 0, now = 0;
    for (i = 1; i <= cnt; i++) {
        if (a[i].l > now)
            res += a[i].l - now, now = a[i].r;
        now = max(now, a[i].r);
    }
    res += 2 * pi - now;
    return res * r[o];
}
int main() {
    while (cin >> n) {
        int i;
        for (i = 1; i <= n; i++) {
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        }
        for (i = 1; i <= n - 1; i++)
            ans += cal(i);
        ans += 2 * pi * r[n];
        printf("%.8lf\n", ans);
    }
}