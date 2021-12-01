/***********************************
// @Author   :   amcones
// @Problem  :   acw896.cpp
// @When     :   2021-11-01 19:50:09
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
vector<int> stk;
int a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stk.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > stk.back())
            stk.push_back(a[i]);
        else {
            *lower_bound(stk.begin(), stk.end(), a[i]) = a[i];
        }
    }
    cout << stk.size();
    return 0;
}