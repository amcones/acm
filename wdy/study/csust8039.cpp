/***********************************
// @Author   :   amcones
// @Problem  :   csust8039.cpp
// @When     :   2022-01-04 01:20:32
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
priority_queue<int> q;
PII cls[maxn];
bool cmp(PII a, PII b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cls[i].first >> cls[i].second;
    sort(cls, cls + n, cmp);
    int minn = 0;
    for (int i = 0; i < n; i++) {
        if (minn + cls[i].first <= cls[i].second) {
            minn += cls[i].first;
            q.push(cls[i].first);
        } else {
            if (!q.size())
                continue;
            if (minn - q.top() <= cls[i].second && q.top() > cls[i].first) {
                minn = minn - q.top() + cls[i].first;
                q.pop();
                q.push(cls[i].first);
            }
        }
    }
    cout << q.size();
    return 0;
}