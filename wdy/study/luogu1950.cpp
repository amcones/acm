#include <cstdio>
int n, m, a, down[3010], s[3010], top, sum[3010];
long long ans = 0; //保险开long long
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++, top = 0) //每一行都要一个独立的单调栈
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a);
            if (a == '*')
                down[j] = i; //该列1所在最深的那一行
            while (top && down[s[top]] < down[j])
                top--; //踢栈
            s[++top] = j;
            sum[top] = sum[top - 1] + (i - down[s[top]]) * (s[top] - s[top - 1]); //递推公式
            ans += sum[top];                                                      //统计答案
        }
    }
    printf("%lld", ans);
    return 0;
}