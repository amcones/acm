/***********************************
// @Author   :   amcones
// @Problem  :   E_MEX_and_Increments.cpp
// @When     :   2021-12-21 11:44:54
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
const int maxn = 2e5 + 10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1), ans(n + 1), st;
        for (int i = 0, j; i < n; i++) {
            cin >> j;
            a[j]++;
        }
        int i, j;
        ll sum = 0;
        for (i = 0; i <= n; i++) {
            ans[i] = sum + a[i];
            if (!a[i]) {
                if (st.size()) {
                    sum += i - st.back();
                    st.pop_back();
                } else
                    break;
            }
            for (j = 1; j < a[i]; j++)
                st.push_back(i);
        }
        for (i++; i <= n; i++)
            ans[i] = -1;
        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}