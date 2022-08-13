/***********************************
// @Author   :   amcones
// @Problem  :   A_Construct_a_Rectangle.cpp
// @When     :   2021-12-27 22:35:20
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
        int l[3];
        for (int i = 0; i < 3; i++)
            cin >> l[i];
        sort(l, l + 3);
        if (l[0] == l[1]) {
            if (l[2] % 2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else if (l[1] == l[2]) {
            if (l[0] % 2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            if (l[0] + l[1] == l[2])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}