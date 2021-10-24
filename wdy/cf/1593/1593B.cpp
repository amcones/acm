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
string s;
int main()
{
    int t;
    cin >> t;
    int num;
    while (t--) {
        cin >> s;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                num = (s[i] - '0') * 10 + (s[j] - '0');
                if (num % 25 == 0) {
                    ans = min(ans, (int)s.size() - i - 2);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}