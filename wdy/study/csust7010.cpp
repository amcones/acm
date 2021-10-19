#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int a[maxn];
int m, q;
int tr[maxn << 2][62], add[maxn << 2], b1[62], b2[62];
int f[62];
vector<int> prime;
bool st[maxn];
int phi[maxn];
void euler(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            prime.push_back(i);
        for (auto j : prime)
        {
            if (j * i > n)
                break;
            st[j * i] = 1;
            if (i % j == 0)
                break;
        }
    }
}
void push_up(int node)
{
    for (int i = 0; i <= m; i++)
    {
        tr[node][i] = max(tr[node << 1][i], tr[node << 1 | 1][i]);
    }
}
void build(int node, int l, int r)
{
    if (l == r)
    {
        tr[node][a[l] % m] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    push_up(node);
}
void push_down(int node, int l, int r)
{
    if (add[node])
    {
        int mid = l + r >> 1;
        memset(b1, 0, sizeof b1);
        memset(b2, 0, sizeof b2);
        for (int i = 0; i <= m; i++)
        {
            if (tr[node << 1][i])
                b1[(i + add[node]) % m] = 1;
            if (tr[node << 1 | 1][i])
                b2[(i + add[node]) % m] = 1;
        }
        for (int i = 0; i <= m; i++)
        {
            tr[node << 1][i] = b1[i];
            tr[node << 1 | 1][i] = b2[i];
        }
        add[node << 1] = (add[node] % m + add[node << 1] % m) % m;
        add[node << 1 | 1] = (add[node] % m + add[node << 1 | 1] % m) % m;
        add[node] = 0;
    }
}
void modify(int a, int b, int c, int node, int l, int r)
{
    if (a <= l && b >= r)
    {
        memset(b1, 0, sizeof b1);
        for (int i = 0; i <= m; i++)
        {
            if (tr[node][i])
                b1[(i + c) % m] = 1;
        }
        for (int i = 0; i <= m; i++)
            tr[node][i] = b1[i];
        add[node] = (add[node] % m + c % m) % m;
    }
    else
    {
        push_down(node, l, r);
        int mid = l + r >> 1;
        if (a <= mid)
            modify(a, b, c, node << 1, l, mid);
        if (b >= mid + 1)
            modify(a, b, c, node << 1 | 1, mid + 1, r);
        push_up(node);
    }
}
void query(int a, int b, int node, int l, int r)
{
    if (a <= l && b >= r)
    {
        int ans = 0;
        for (auto i : prime)
        {
            if (tr[node][i])
                f[i] = 1;
        }
        return;
    }
    push_down(node, l, r);
    int mid = l + r >> 1;
    if (mid >= a)
        query(a, b, node << 1, l, mid);
    if (mid + 1 <= b)
        query(a, b, node << 1 | 1, mid + 1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> m;
    euler(m);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
    }
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        int oper, l, r, val;
        cin >> oper >> l >> r;
        if (oper == 1)
        {
            cin >> val;
            modify(l, r, val % m, 1, 1, n);
        }
        else
        {
            memset(f, 0, sizeof f);
            query(l, r, 1, 1, n);
            cout << accumulate(f, f + m, 0) << endl;
        }
    }
    return 0;
}