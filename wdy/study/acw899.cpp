/***********************************
// @Author   :   amcones
// @Problem  :   acw899.cpp
// @When     :   2021-11-01 21:10:39
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
const int maxn = 1e4 + 10;
char a[maxn][15];
int dp[maxn][maxn];
int edit_distance(char a[], char b[]) {
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 0; i <= lb; i++)
        dp[0][i] = i;
    for (int i = 0; i <= la; i++)
        dp[i][0] = i;
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + !(a[i] == b[j])});
        }
    }
    return dp[la][lb];
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> (a[i] + 1);
    while (m--) {
        char s[15];
        int limit;
        cin >> (s + 1) >> limit;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (edit_distance(a[i], s) <= limit)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}