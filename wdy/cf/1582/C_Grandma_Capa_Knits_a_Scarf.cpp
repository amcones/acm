/***********************************
// @Author   :   amcones
// @Problem  :   C_Grandma_Capa_Knits_a_Scarf.cpp
// @When     :   2021-10-24 19:18:15
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0x3f3f3f3f;
        bool f = true;
        for (int i = 'a'; i <= 'z'; i++) {
            f = true;
            int tmp = 0;
            for (int p1 = 0, p2 = s.size() - 1 - p1; p1 <= p2;) {
                if (s[p1] == s[p2])
                    p1++, p2--;
                else {
                    if (s[p1] == i)
                        p1++, tmp++;
                    else if (s[p2] == i)
                        p2--, tmp++;
                    else {
                        f = false;
                        break;
                    }
                }
            }
            if (f)
                ans = min(ans, tmp);
        }
        if (ans == 0x3f3f3f3f)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}