//要使a^2-b^2+c^2-d^2最大
//即让a和c取到区间最大和次大值，b和d取到区间最小和次小值
//还要维护取一对的最大值，取一对再取另一个区间的最大值，取一对再取另一个区间的最小值，选了两对的最大值
/***********************************
// @Author   :   amcones
// @Problem  :   DOS_Card.cpp
// @When     :   2022-07-29 15:27:44
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
const int maxn = 2e5 + 10;
ll a[maxn];
int n, m;

struct node {
    int len;//节点支配区间长度
    ll max1, max2, min1, min2, res1, res2, res1_max, res1_min;
    node(int len = 0) {
        this->len = len;
        max1 = max2 = -1e18, min1 = min2 = 1e18;
        res1 = res2 = res1_max = res1_min = -1e18;
    }
    void update_max(ll v) {//维护更新最大次大值
        if (v > max1)
            max2 = max1, max1 = v;
        else if (v > max2)
            max2 = v;
    }
    void update_min(ll v) {//维护更新最小次小值
        if (v < min1)
            min2 = min1, min1 = v;
        else if (v < min2)
            min2 = v;
    }
    node operator+(const node& A) const {//维护合并节点操作
        if (len == 0)
            return A;
        if (A.len == 0)
            return *this;
        node T(len + A.len);//合并后的父节点
        T.update_max(max1);
        T.update_max(max2);
        T.update_max(A.max1);
        T.update_max(A.max2);
        T.update_min(min1);
        T.update_min(min2);
        T.update_min(A.min1);
        T.update_min(A.min2);
        //选了两对的最大值
        T.res2 = max(T.res2, res2);
        T.res2 = max(T.res2, A.res2);
        T.res2 = max(T.res2, res1 + A.res1);
        T.res2 = max(T.res2, max1 + max2 - A.min1 - A.min2);
        T.res2 = max(T.res2, res1_max - A.min1);
        T.res2 = max(T.res2, max1 + A.res1_min);
        //选了一对的最大值
        T.res1 = max(T.res1, res1);
        T.res1 = max(T.res1, A.res1);
        T.res1 = max(T.res1, max1 - A.min1);
        //选了一对加上另一个区间的最大值
        T.res1_max = max(T.res1_max, res1_max);
        T.res1_max = max(T.res1_max, A.res1_max);
        T.res1_max = max(T.res1_max, res1 + A.max1);
        T.res1_max = max(T.res1_max, A.res1 + max1);
        if (A.len >= 2)//区间里至少有2个数
            T.res1_max = max(T.res1_max, max1 - A.min1 + A.max1);//自己区间减去对面区间的最小值加上对面区间的最大值
        if (len >= 2)
            T.res1_max = max(T.res1_max, max1 - A.min1 + max2);//自己区间的最大值减去对面区间的最小值加上自己区间的次大值
        //选了一对减去另一个区间的最小值
        T.res1_min = max(T.res1_min, res1_min);
        T.res1_min = max(T.res1_min, A.res1_min);
        T.res1_min = max(T.res1_min, res1 - A.min1);
        T.res1_min = max(T.res1_min, A.res1 - min1);
        if (A.len >= 2)
            T.res1_min = max(T.res1_min, max1 - A.min1 - A.min2);
        if (len >= 2)
            T.res1_min = max(T.res1_min, max1 - A.min1 - min1);

        return T;
    }
} tree[maxn << 2];

void build(int l = 1, int r = n, int p = 1) {
    if (l == r) {
        tree[p] = node(1);
        tree[p].max1 = tree[p].min1 = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1), build(mid + 1, r, p << 1 | 1);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

node query(int a, int b, int l = 1, int r = n, int p = 1) {
    if (l > b || r < a)
        return node(0);
    if (l >= a && r <= b)
        return tree[p];
    int mid = l + r >> 1;
    return query(a, b, l, mid, p << 1) + query(a, b, mid + 1, r, p << 1 | 1);
}

void init() {
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], a[i] *= a[i];
    }
    build();
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r).res2 << endl;
    }
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}