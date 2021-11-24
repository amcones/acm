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
int fa[maxn];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void comb(int x, int y)
{
    fa[find(x)] = find(y);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M')
            comb(a, b);
        else
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }
    return 0;
}