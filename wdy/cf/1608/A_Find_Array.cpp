/***********************************
// @Author   :   amcones
// @Problem  :   A_Find_Array.cpp
// @When     :   2021-12-11 18:05:40
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
int a[1100];
bool st[maxn];
vector<int> prime;
void euler(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            prime.push_back(i);
        for (auto j : prime) {
            if (j * i > n)
                break;
            st[j * i] = 1;
            if (i % j == 0)
                break;
        }
    }
}
int main() {
    int t;
    cin >> t;
    euler(maxn);
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << prime[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}