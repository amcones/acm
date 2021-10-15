/***********************************
// @Author   :   amcones
// @Problem  :   ceil_floor.cpp
// @When     :   2021-10-11 23:09:09
***********************************/
#include <algorithm>
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
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v)
        is >> i;
    return is;
}
int main() {
    int a = 13, b = 4;
    cout << "ceil:" << (a + b - 1) / b << endl;
    cout << "floor:" << a / b << endl;
    a = -2, b = -3;
    cout << (a & b && (a ^ b) < 0) << endl;
    vector<int> s;
    cin >> s;
    return 0;
}