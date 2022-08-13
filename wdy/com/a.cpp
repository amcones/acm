#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, q;
char s[N];
ll f[N][10], g[N][10][10];
// g[i][j][k]前i个字符第一位为j第二位为k的子序列数量
// f[i][j]前i个字符中j的数量
void sol() {
    cin >> n >> q >> (s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 9; j++)
            f[i][j] = f[i - 1][j];
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                g[i][j][k] = g[i - 1][j][k];
        for (int j = 0; j <= 9; j++)
            g[i][j][s[i] - '0'] += f[i - 1][j];
        f[i][s[i] - '0']++;
    }
    while (q--) {
        int l, r, op;
        cin >> l >> r >> op;
        int a = op / 10, b = op % 10;
        ll ans = g[r][a][b] - g[l - 1][a][b] - (f[r][b] - f[l - 1][b]) * f[l - 1][a];  //减掉被重复算的
        cout << ans << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    sol();
    return 0;
}