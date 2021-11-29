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
int t, m;
int w[maxn], v[maxn];
int dp[maxn];
int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= m; i++)
        for (int j = t; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[t];
    return 0;
}