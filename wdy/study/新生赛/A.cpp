/***********************************
// @Author   :   amcones
// @Problem  :   A.cpp
// @When     :   2021-11-29 22:40:33
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
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else if (n == 1 || m == 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}