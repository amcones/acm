/***********************************
// @Author   :   amcones
// @Problem  :   B_William_the_Vigilant.cpp
// @When     :   2021-11-29 10:35:16
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
const int maxn = 1e5 + 10;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    auto Is = [&](int i) { return 0 <= i && i - 2 < n && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'; };
    for (int i = 0; i < n - 2; i++)
        ans += Is(i);
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        i--;
        ans -= Is(i - 2);
        ans -= Is(i - 1);
        ans -= Is(i);
        s[i] = c;
        ans += Is(i);
        ans += Is(i - 1);
        ans += Is(i - 2);
        cout << ans << endl;
    }

    return 0;
}