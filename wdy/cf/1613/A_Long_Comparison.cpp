/***********************************
// @Author   :   amcones
// @Problem  :   A_Long_Comparison.cpp
// @When     :   2021-12-01 22:35:32
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
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        //先比位数，相同再比前面
        int y1 = x1, y2 = x2;
        int q1 = p1, q2 = p2;
        while (y1) {
            p1++, y1 /= 10;
        }
        while (y2) {
            p2++, y2 /= 10;
        }
        while (x1 % 10 == 0)
            x1 /= 10, q1++;
        while (x2 % 10 == 0)
            x2 /= 10, q2++;
        if (p1 == p2) {
            while (q1 > q2)
                x1 *= 10, q1--;
            while (q2 > q1)
                x2 *= 10, q2--;
            if (x1 == x2)
                cout << '=' << endl;
            else
                cout << (x1 < x2 ? '<' : '>') << endl;
        } else {
            cout << (p1 < p2 ? '<' : '>') << endl;
        }
    }
    return 0;
}