#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int a[3], A[3];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++)
            cin >> a[i];
        int maxn = max({ a[0], a[1], a[2] });
        int cnt = 0, maxp = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] == maxn)
                cnt++, maxp = i;
        }
        bool f = false;
        if (cnt > 1)
            f = true;
        for (int i = 0; i < 3; i++) {
            if (maxp == i)
                cout << maxn + f - a[i] << ' ';
            else
                cout << maxn + 1 - a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}