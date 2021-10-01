#include <iostream>
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
//n*(n-1)/2
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        if (k < 2)
            cout << "NO\n";
        else if (m > n * (n - 1) / 2 || m < n - 1)
            cout << "NO\n";
        else if (k == 2)
        {
            if (n == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (k == 3)
        {
            if (m == n * (n - 1) / 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "YES\n";
    }
    return 0;
}