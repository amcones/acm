#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int a[maxn];
vector<int> mp[maxn];
int n, k, sum, cnt;
int dfs(int u, int fa)
{
    int s = a[u];
    for (auto v : mp[u])
        if (v != fa)
            s ^= dfs(v, u);
    if (s == sum)
        s = 0, cnt++;
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            mp[i].clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum ^= a[i];
        }
        int u, v;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            mp[u].push_back(v), mp[v].push_back(u);
        }
        if (!sum)
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            cnt = 0;
            dfs(1, -1);
            if (k >= 3 && cnt >= 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}