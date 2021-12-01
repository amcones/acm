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
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int fa[maxn];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void comb(int a, int b)
{
    int x = find(a), y = find(b);
    fa[x] = y;
}
int ans = 0;
int main()
{
    for (int i = 1; i < maxn; i++) //同类，捕食，天敌
        fa[i] = i;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (d == 1)
        {
            if (find(x) == find(y + n) || find(x) == find(y + n + n))
                ans++;
            else
            {
                comb(x, y), comb(x + n, y + n), comb(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            if (x == y || find(x) == find(y) || find(x + n + n) == find(y))
                ans++;
            else
            {
                comb(x + n, y), comb(y + n, x + n + n), comb(x, y + n + n);
            }
        }
    }
    cout << ans << endl;
    return 0;
}