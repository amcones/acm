/***********************************
// @Author   :   amcones
// @Problem  :   B_Berland_Music.cpp
// @When     :   2021-12-27 22:40:06
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
int p[maxn];
//重新给每首歌打分
//不喜欢的要在后面
//分别排列喜欢和不喜欢的
//使得预测分和重新打分差最小
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        map<int, int> mp;
        vector<PII> a, b;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0')
                a.push_back({p[i], i});
            else
                b.push_back({p[i], i});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int k = 1;
        for (auto i : a) {
            mp[i.second] = k++;
        }
        for (auto i : b) {
            mp[i.second] = k++;
        }
        for (int i = 1; i <= n; i++) {
            cout << mp[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}