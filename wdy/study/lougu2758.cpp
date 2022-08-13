/***********************************
// @Author   :   amcones
// @Problem  :   lougu2758.cpp
// @When     :   2022-01-03 12:11:30
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
int f[3000][3000];
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 1; i <= a.length(); i++) {
        f[i][0] = i;
    }
    for (int i = 1; i <= b.length(); i++) {
        f[0][i] = i;
    }
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
            }
        }
    }
    cout << f[a.length()][b.length()] << endl;
    return 0;
}