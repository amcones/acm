/***********************************
// @Author   :   amcones
// @Problem  :   D_Moderate_Modular_Mode.cpp
// @When     :   2021-10-31 00:10:10
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (x > y)
            cout << x + y << endl;
        else if (!(y % x))
            cout << x << endl;
        else {
            cout << (y - y % x / 2) << endl;
        }
    }
    return 0;
}