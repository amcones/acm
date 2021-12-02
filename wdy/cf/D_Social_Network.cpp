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
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
//给d条关系，可以加d条边，xiyi必须联通
//如果已经连通，那么这条边是多余的，可以连在别的地方
//肯定让前k大的连通块连通
int fa[maxn], s[maxn];
int cnt = 0;
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(x);
}
void comb(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        cnt++;
    else
    {
        fa[fy] = fx, s[fx] += s[fy];
    }
}
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i, s[i] = 1;
    }
    while (d--)
    {
        int x, y;
        cin >> x >> y;
        comb(x, y);
        vector<int> vec;
        for (int i = 1; i <= n; i++)
            if (fa[i] == i)
                vec.push_back(s[i]);
        sort(vec.begin(), vec.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i <= cnt && i < vec.size(); i++)
        {
            ans += vec[i];
        }
        cout << ans - 1 << endl;
    }
    return 0;
}