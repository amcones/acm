#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
#define endl '\n'

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<long long, int> PLI;
typedef pair<string, string> PSS;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m;
int dp[505][255], a[505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int j = (i + 1) / 2; j <= n / 2 && j <= i; j++) {
                if (a[i] == 0)
                    dp[i][j] = (dp[i - 1][j - 1] * m % mod + dp[i - 1][j]) % mod;
                else if (a[i] > 0)
                    dp[i][j] = dp[i - 1][j - 1] % mod;
                else if (a[i] < 0)
                    dp[i][j] = dp[i - 1][j] / 2 % mod;
            }
        }
        cout << dp[n][n / 2] << endl;
    }
    return 0;
}