/***********************************
// @Author   :   amcones
// @Problem  :   B_Squares_and_Cubes.cpp
// @When     :   2021-12-20 22:37:56
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
const int maxn = 1e9;
vector<ll> num;
int main() {
    num.clear();
    for (ll i = 1; i <= 31623; i++) {
        if (i * i * i <= maxn)
            num.push_back(i * i * i);
        if (i * i <= maxn)
            num.push_back(i * i);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());  // 去重
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << upper_bound(num.begin(), num.end(), n) - num.begin() << endl;
    }
    return 0;
}