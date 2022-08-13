/***********************************
// @Author   :   amcones
// @Problem  :   C_BA_String.cpp
// @When     :   2021-12-19 00:20:13
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
        ll n, k, x;
        cin >> n >> k >> x;
        --x;
        string s;
        cin >> s;
        vector<int> base;
        int len = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                base.push_back(len * k + 1);
                len = 0;
            } else {
                len++;
            }
        }
        base.push_back(len * k + 1);
        string res;
        for (auto b : base) {
            int y = x % b;
            res += string(y, 'b') + 'a';
            x /= b;
        }
        res.pop_back();
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}