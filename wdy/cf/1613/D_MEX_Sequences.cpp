#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
using ll = long long;
ll cnt[500005], a[500005], dp[500005][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n + 2; i++)
            cnt[i] = 0, dp[i][0] = dp[i][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ++cnt[a[i]];
        }
        dp[0][0] = 1;
        //mex=x时，最大值可能是x-1或x+1
        //dp[x][0]表示mex=x时最大值为x-1,可以接着接
        //dp[x][1]表示mex=x时最大值为x+1，只能左右横跳了
        for (int i = 1; i <= n; i++)
        {
            //mex=x+1
            //加一个数进来有取和不取两种可能
            dp[a[i] + 1][0] = (dp[a[i] + 1][0] + dp[a[i] + 1][0]) % mod;
            dp[a[i] + 1][1] = (dp[a[i] + 1][1] + dp[a[i] + 1][1]) % mod;
            //mex=x
            dp[a[i] + 1][0] = (dp[a[i] + 1][0] + dp[a[i]][0]) % mod;
            //mex=x-1
            if (a[i])
            {
                dp[a[i] - 1][1] = (dp[a[i] - 1][1] + dp[a[i] - 1][1]) % mod;
                dp[a[i] - 1][1] = (dp[a[i] - 1][1] + dp[a[i] - 1][0]) % mod;
            }
        }
        ll ans = 0;
        for (int i = 0; i <= n + 2; i++)
            ans += dp[i][0] + dp[i][1];
        cout << (ans + mod - 1) % mod << "\n";
    }
    return 0;
}