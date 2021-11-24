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
const int mod = 998244353;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll res = 1;
        for (int i = 1; i <= n; i++)
        {
            res = res * i % mod;
        }
        cout << res << endl;
    }
    return 0;
}