/***********************************
// @Author   :   amcones
// @Problem  :   acw837.cpp
// @When     :   2021-11-23 18:12:13
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
int fa[maxn];
int Size[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void comb(int a, int b) {
    int x = find(a), y = find(b);
    Size[y] += Size[x];
    fa[x] = y;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i, Size[i] = 1;
    while (m--) {
        string op;
        int a, b;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            if (find(a) != find(b))
                comb(a, b);
        } else if (op == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes\n";
            else
                cout << "No\n";
        } else {
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }
    return 0;
}