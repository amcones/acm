/***********************************
// @Author   :   amcones
// @Version  :   1.0
// @Problem  :   A_Infinite_Fence.cpp
// @When     :   2021-10-11 19:34:09
***********************************/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
//两种颜色各自循环
//固定一种颜色，另一种颜色在这一区间内的数量<k
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, b, k;
        cin >> r >> b >> k;
        int a = __gcd(r, b);
        r /= a, b /= a;
        if (r < b)
            swap(r, b);
        int ans = (r - 2) / b + 1;
        if (ans >= k)
            cout << "REBEL\n";
        else
            cout << "OBEY\n";
    }
    return 0;
}