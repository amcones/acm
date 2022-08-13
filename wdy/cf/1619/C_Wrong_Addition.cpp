/***********************************
// @Author   :   amcones
// @Problem  :   C_Wrong_Addition.cpp
// @When     :   2021-12-20 23:32:57
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
        vector<int> ans;
        string a, s;
        cin >> a >> s;
        if (s.length() < s.length()) {
            cout << -1 << endl;
            continue;
        }
        bool f = true;
        int i, j;
        for (i = s.length() - 1, j = a.length() - 1; i >= 0 && j >= 0; i--, j--) {
            if (s[i] - a[j] >= 0) {
                ans.push_back(s[i] - a[j]);
            } else {
                if (i < 1) {
                    f = false;
                    break;
                }
                int numa, numb, nums;
                numa = a[j] - '0', nums = (s[i] - '0') + (s[i - 1] - '0') * 10;
                numb = nums - numa;
                if (numb > 9 || numb < 0) {
                    f = false;
                    break;
                }
                ans.push_back(numb);
                i--;
            }
        }
        for (; i >= 0; i--)
            ans.push_back(s[i] - '0');
        if ((i < 0 && j >= 0) || !f)
            cout << -1 << endl;
        else {
            reverse(ans.begin(), ans.end());
            bool ok = false;
            for (auto i : ans) {
                if (i != 0)
                    ok = true;
                if (ok)
                    cout << i;
            }
            if (!ok)
                cout << 0;
            cout << endl;
        }
    }
    return 0;
}