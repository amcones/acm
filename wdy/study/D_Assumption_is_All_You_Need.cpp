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
const int maxn = 3000;
const int mod = 1e9 + 7;
int a[maxn], b[maxn], pa[maxn], pb[maxn];
bool vis[maxn];
vector<PII> ans;
int n;
void solve()
{
    memset(vis, 0, sizeof vis);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], pa[a[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i], pb[b[i]] = i;
    for (int i = n; i >= 1; i--) //将i从pa[i]放到pb[i]
    {
        if (pa[i] > pb[i])
        {
            cout << -1 << endl;
            return;
        }
        if (pa[i] == pb[i])
            continue;
        int maxx = 0, maxp = 0;
        for (int j = pb[i]; j > pa[i]; j--)
        {
            if (a[j] > maxx && !vis[a[j]])
                maxx = a[j], maxp = j;
        }
        swap(a[maxp], a[pa[i]]);
        ans.push_back({pa[i], maxp});
        swap(pa[maxx], pa[i]);
        vis[i] = true;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        if (ans.size())
        {
            cout << ans.size() << endl;
            for (auto i : ans)
                cout << i.first << ' ' << i.second << endl;
        }
        ans.clear();
    }
    return 0;
}