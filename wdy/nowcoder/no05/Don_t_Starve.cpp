#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2010;

int n;
int x[N], y[N];
struct ha {
    int dis, x, y;
} a[N * N];
int cmp(ha x, ha y) {
    return x.dis > y.dis;
}
int sta1[N * N], sta2[N * N], top;
int tot;

int Max[N];
void Commit() {
    while (top) {
        Max[sta1[top]] = max(Max[sta1[top]], sta2[top]);
        top--;
    }
}

signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            a[++tot] = (ha){(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), i, j};
        }
    sort(a + 1, a + tot + 1, cmp);
    for (int i = 1; i <= n; i++)
        Max[i] = -1000000000;
    int Ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (a[i].dis != a[i - 1].dis)
            Commit();
        int tmp = Max[a[i].x] + 1;
        sta1[++top] = a[i].y;
        sta2[top] = tmp;
    }
    Commit();
    for (int i = 1; i <= n; i++)
        Ans = max(Ans, Max[i]);
    cout << Ans << endl;
}