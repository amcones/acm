/***********************************
// @Author   :   amcones
// @Problem  :   A_Equal_or_Not_Equal.cpp
// @When     :   2021-12-18 23:36:29
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
// NEEEEE||EEEEN||EEEEENEEEE
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool f1 = true, f2 = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'N') {
                f1 = false, f2 = false;
                for (int j = 0; j < s.length(); j++) {
                    if (j == i)
                        continue;
                    if (s[j] != 'E') {
                        cout << "YES\n";
                        f1 = true;
                        break;
                    }
                }
                break;
            }
        }
        if (!f1)
            cout << "NO\n";
        if (f2)
            cout << "YES\n";
    }
    return 0;
}