/***********************************
// @Author   :   amcones
// @Problem  :   A_Square_String_.cpp
// @When     :   2021-12-20 22:35:51
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
        string s;
        cin >> s;
        if (s.size() & 1)
            cout << "NO\n";
        else {
            bool f = true;
            for (int i = 0; i < s.size() / 2; i++) {
                if (s[i] != s[i + s.size() / 2]) {
                    f = false;
                    cout << "NO\n";
                    break;
                }
            }
            if (f)
                cout << "YES\n";
        }
    }
    return 0;
}