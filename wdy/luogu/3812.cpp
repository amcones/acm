/***********************************
// @Author   :   amcones
// @Problem  :   3812.cpp
// @When     :   2021-10-28 20:47:23
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
ll n, p[100], d[100], cnt, top;
bool zero;
void insert(ll x) {//构造线性基
    for (int i = 63; ~i; i--) {
        if (x & 1ll << i) {
            if (p[i])
                x ^= p[i];
            else {
                p[i] = x, cnt++;
                break;
            }
        }
    }
    zero = cnt != n;
}
bool check(ll x) {//检验存在性
    for (int i = 63; ~i; i--)
        if (x & 1ll << i)
            x ^= p[i];
    return x == 0;
}
ll qmax() {//最大值
    ll res = 0;
    for (int i = 63; ~i; i--)
        (res ^ p[i]) > res ? res ^= p[i] : 1;
    return res;
}
ll qmin() {//最小值
    for (int i = 0; i <= 63; i++)
        if (p[i])
            return p[i];
    return 0;
}
void rebuild() {//重建线性基
    cnt = 0, top = 0;
    for (int i = 63; ~i; i--)
        for (int j = i - 1; ~j; j--)
            if (p[i] & 1ll << j)
                p[i] ^= p[j];
    for (int i = 0; i <= 63; i++)
        if (p[i])
            d[cnt++] = p[i];
}
ll kth(int k) {//查第k大
    if (zero)
        k--;
    if (k >= 1ll << cnt)
        return -1;
    ll ans = 0;
    for (int i = 63; ~i; i--)
        if (k & 1ll << i)
            ans ^= d[i];
    return ans;
}
int rank(ll x) {//查询排名
    int ans = 0;
    for (int i = cnt - 1; i >= 0; i--)
        if (x >= d[i])
            ans += 1 << i, x ^= d[i];
    return ans + zero;
}
int main() {
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        insert(x);
    }
    cout << qmax() << endl;
    return 0;
}