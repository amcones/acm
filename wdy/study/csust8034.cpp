/***********************************
// @Author   :   amcones
// @Problem  :   csust8034.cpp
// @When     :   2022-01-04 01:07:55
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
int a;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        q.push(a);
    }
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        q.push(max(x, y) + t);
    }
    cout << q.top();
    return 0;
}