/***********************************
// @Author   :   amcones
// @Problem  :   1003.cpp
// @When     :   2022-07-26 12:00:50
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

void init() {
}
void solve() {
    string s;
    getline(cin, s);
    cout << (char)(s[0] - 'a' + 'A');
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == ' ')
            cout << (char)(s[i] - 'a' + 'A');
    }
    cout << endl;
}
int main() {
    int t = 1;
    cin >> t;
    getchar();
    while (t--) {
        init();
        solve();
    }
    return 0;
}