/***********************************
// @Author   :   amcones
// @Problem  :   generator.cpp
// @When     :   2021-11-26 18:54:25
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
#include "testlib.h"
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
char mp[2] = {'#', '.'};
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 10; i++) {
        startTest(i);
        int n = rnd.next(1, 1000);
        int m = rnd.next(1, 1000);
        cout << n << ' ' << m << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << mp[rnd.next(0, 1)];
            }
            cout << endl;
        }
    }
    return 0;
}