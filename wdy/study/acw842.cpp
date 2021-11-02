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
int n;
int ans[10], vis[10];
void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans[u] = i;
            vis[i] = 1;
            dfs(u + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}