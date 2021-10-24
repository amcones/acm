
/***********************************
// @Author   :   amcones
// @Problem  :   csust8018.cpp
// @When     :   2021-10-24 12:45:28
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
const int maxn = 5e2 + 10;
int mp[maxn][maxn];
int del[maxn];
vector<int> u;
ll ans[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mp[i][j];
    for (int i = n; i >= 1; i--)
        cin >> del[i];
    for (int k = 1; k <= n; k++) {
        u.push_back(del[k]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mp[i][j] = min(mp[i][j], mp[i][del[k]] + mp[del[k]][j]);
        for (auto i : u)
            for (auto j : u)
                ans[k] += mp[i][j];
    }
    for (int i = n; i >= 1; i--)
        cout << ans[i] << ' ';
    return 0;
}