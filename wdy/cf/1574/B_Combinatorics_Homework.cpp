#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
//每个字母w都有w-1的空，用别的字母去塞，少几个就是至少几对
//如果塞满了还有多的，那么
int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll w[3], m;
        cin >> w[0] >> w[1] >> w[2] >> m;
        sort(w, w + 3);
        ll res = max(0ll, w[0] + w[1] + w[2] - 3);
        ll mn = 0;
        if (w[2] - w[1] - w[0] > 1)
            mn = w[2] - 1 - w[1] - w[0];
        if (m >= mn && m <= res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}