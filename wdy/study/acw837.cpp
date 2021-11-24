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
int fa[maxn], Size[maxn];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void comb(int x, int y)
{
    Size[find(y)] += Size[find(x)]; //注意顺序，要么先存起来
    fa[find(x)] = find(y);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i, Size[i] = 1;
    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "C")
        {
            cin >> a >> b;
            if (find(a) != find(b))
                comb(a, b);
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        }
        else
        {
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }
    return 0;
}