#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int fa[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
    int n, m;
    cin >> n >> m;
    int ans = n - 1;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v))
            ans--, fa[find(u)] = find(v);
    }
    cout << ans << endl;
    return 0;
}