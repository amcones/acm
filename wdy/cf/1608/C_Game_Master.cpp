/***********************************
// @Author   :   amcones
// @Problem  :   C_Game_Master.cpp
// @When     :   2021-12-11 19:39:36
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
int a[maxn], b[maxn];
//要为第i个人尽可能减小代价
//那么可以反复横跳
//找到满足a[1]<a[2]&&b[1]>b[2],a[2]<a[3]&&b[2]>b[3]...
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p1 = 1, p2 = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[p1] < a[i])
                p1 = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[p2] < b[i])
                p2 = i;
        }
        for (int i = 1; i <= n; i++) {
            if (i == p1 || i == p2) {
                cout << 1;
                continue;
            }
            if (max(a[i], b[i]) > min(b[p1], a[p2]))
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}