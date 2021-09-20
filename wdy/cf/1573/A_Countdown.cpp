#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                ans += s[i] - '0';
            else
                ans += s[i] - '0' == 0 ? 0 : s[i] - '0' + 1;
        }
        cout << ans << endl;
    }
    return 0;
}