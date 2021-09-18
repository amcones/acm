#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x[4], y[4], m[1010];
    for (int i = 1; i <= 3; i++) {
        scanf("%d%d", &x[i], &y[i]);
        m[x[i]] = y[i];
    }
    sort(x + 1, x + 4);
    sort(y + 1, y + 4);
    printf("%d\n", x[3] - x[1] + y[3] - y[1] + 1);
    for (int i = x[1]; i < x[2]; i++)
        printf("%d %d\n", i, m[x[1]]);
    for (int i = x[3]; i > x[2]; i--)
        printf("%d %d\n", i, m[x[3]]);
    for (int i = y[1]; i <= y[3]; i++)
        printf("%d %d\n", x[2], i);
}