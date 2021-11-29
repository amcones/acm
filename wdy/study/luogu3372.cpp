#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int a[maxn];
int tree[maxn << 2], b[maxn << 2];
void push_up(int node)
{
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
void push_down(int node, int len)
{
    b[node << 1] += b[node];
    b[node << 1 | 1] += b[node];
    tree[node << 1] += b[node] * (len - len / 2);
    tree[node << 1 | 1] += b[node] * (len / 2);
    b[node] = 0;
}
void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    push_up(node);
}
void update(int node, int l, int r, int L, int R, int k)
{
    if (L <= l && R >= r)
        tree[node] += (R - L + 1) * k, b[node] += k;
    int mid = l + r >> 1;
    push_down(node, R - L + 1);
    update(node << 1, l, r, L, mid, k);
    update(node << 1 | 1, l, r, mid + 1, R, k);
    push_up(node);
}
int query(int node, int l, int r, int L, int R)
{
    if (L <= l && R >= r)
        return tree[node];
    int mid = L + R >> 1;
    push_down(node, R - L + 1);
    return query(node << 1, l, r, L, mid) + query(node << 1 | 1, l, r, mid + 1, R);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int oper, l, r, k;
    while (m--)
    {
        cin >> oper;
        if (oper == 1)
        {
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}