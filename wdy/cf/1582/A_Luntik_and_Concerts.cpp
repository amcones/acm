/***********************************
// @Author   :   amcones
// @Problem  :   A_Luntik_and_Concerts.cpp
// @When     :   2021-10-24 20:26:24
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
        ll a, b, c;
        cin >> a >> b >> c;
        b <<= 1, c *= 3;
        cout << (a + b + c) % 2 << endl;
    }
    return 0;
}