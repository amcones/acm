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
        ll n = rnd.next(1ll, 1000000000000000000ll);
        int k = rnd.next(2, 10);
        cout << n << ' ' << k;
    }
    return 0;
}