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
int a[400];
int dp[400][400];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            dp[l][r] = 0x3f3f3f3f;
            for (int i = l; i < r; i++)
            {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + a[r] - a[l - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}