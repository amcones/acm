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
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
pair<PII, int> node[maxn];
int fa[maxn], s[maxn];
int find(int x)
{
    if (fa[x] == x)
        return x;
    int t = fa[x];
    fa[x] = find(fa[x]);
    s[x] += s[t];
    s[x] %= 2;
    return fa[x];
}
void comb(int x, int y, int w)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        fa[fy] = fx;
        s[fy] = s[x] - s[y] + w + 2;
        s[fy] %= mod;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> node[i].first.first >> node[i].first.second >> node[i].second;
    }
    sort(node, node + m, [](pair<PII, int> a, pair<PII, int> b)
         { return a.second > b.second; });
    for (int i = 0; i < maxn; i++)
        fa[i] = i, s[i] = 0;
    for (int i = 0; i < m; i++)
    {
        int a = node[i].first.first, b = node[i].first.second, v = node[i].second;
        if (find(a) == find(b))
        {
            if (s[a] == s[b])
            {
                cout << v << endl;
                return 0;
            }
        }
        else
        {
            comb(a, b, 1);
        }
    }
    cout << 0 << endl;
    return 0;
}