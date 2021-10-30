/***********************************
// @Author   :   amcones
// @Problem  :   acw830.cpp
// @When     :   2021-10-30 10:19:35
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
stack<int> s;
int main() {
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!s.empty() && s.top() >= a)
            s.pop();
        if (!s.empty())
            cout << s.top() << ' ';
        else
            cout << -1 << ' ';
        s.push(a);
    }
    return 0;
}