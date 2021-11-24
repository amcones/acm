#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int fa[maxn], sum[maxn];
int n, m;
int ans;
void init()
{
    ans = 0;
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < maxn; i++)
        fa[i] = i;
}
int find(int x)
{
    if (x == fa[x])
        return x;
    int t = fa[x];
    fa[x] = find(fa[x]);
    sum[x] += sum[t];
    return fa[x];
}
void comb(int a, int b, int num)
{
    int x = find(a), y = find(b);
    if (x == y)
    {
        if (sum[b] != sum[a] + num)
            ans++;
    }
    else
    {
        fa[y] = x;
        sum[y] = sum[a] + num - sum[b];
    }
}
int main()
{
    while (cin >> n >> m)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            comb(a - 1, b, c);
        }
        cout << ans << endl;
    }
    return 0;
}