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
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
ll a[maxn], t1[maxn], t2[maxn];
ll dp[4][4];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= 3;
        t1[i] = (t1[i - 1] + a[i]) % 3;
        t2[i] = (t2[i - 1] + a[i] * a[i]) % 3;
    }
    ll ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int a = t1[i] - j, b = t2[i] - k;
                a *= a;
                if ((a - b) % 3 == 0)
                    ans += dp[j][k];
            }
        }
        dp[t1[i]][t2[i]]++;
    }
    cout << ans << endl;
    return 0;
}