/***********************************
// @Author   :   amcones
// @Problem  :   acw92.cpp
// @When     :   2021-11-22 20:46:31
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
int n;
void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            if (state >> i & 1)
                cout << i + 1 << ' ';
        }
        cout << endl;
        return;
    }
    dfs(u + 1, state);
    dfs(u + 1, state | 1 << u);
}
int main() {
    cin >> n;
    dfs(0, 0);
    return 0;
}