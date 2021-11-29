#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main()
{
    ll x, y;
    cin >> x >> y;
    ll t = x ^ y;
    if (t <= x)
    {
        cout << 1 << endl;
        cout << t << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << y << ' ' << x << endl;
    }
    return 0;
}