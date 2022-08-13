// Created by jamesamcones on 2022/8/1 23:33
#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

string s[20];
int ne[20][20];
struct seg {
    int l, r, id;
};
vector<seg> vec;
vector<int> ans;

void init() {
    vector<seg>().swap(vec);
    vector<int>().swap(ans);
}

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        cin >> s[k];
        for (int i = 1, j = 0; i < s[k].length(); i++) {
            while (j && s[k][i] != s[k][j])
                j = ne[k][j - 1];
            if (s[k][i] == s[k][j])
                j++;
            ne[k][i] = j;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 0, j = 0; i < t.length(); i++) {
            while (j && t[i] != s[k][j])
                j = ne[k][j - 1];
            if (t[i] == s[k][j])
                j++;
            if (j == s[k].length()) {
                // cout<<i-s[k].length()+1<<' '<<i<<endl;
                vec.push_back({int(i - s[k].length() + 1), i, k});
                j = ne[k][j - 1];
            }
        }
    }
    sort(vec.begin(), vec.end(), [](const seg& a, const seg& b) {
        return a.l != b.l ? a.l < b.l : a.r > b.r;
    });
    if (vec.empty() || vec[0].l != 0) {  //最左边无法覆盖到
        cout << -1 << endl;
        return;
    }
    int r = vec[0].r;
    int pos = 0;
    bool f = false;
    ans.push_back(0);                       //第一个一定是最靠左且覆盖到最右边的
    for (int i = 1; i < vec.size(); i++) {  //每一次找到能够覆盖前面且覆盖到最后面的
        if (r == t.length() - 1)
            break;  //覆盖到底了
        f = false;
        while (i < vec.size()) {                                       //从当前位置往后找，找到左区间最左，右区间最右，后面不会有能够覆盖到更右边的区间了
            if (seg last = vec[ans.back()]; vec[i].l <= last.r + 1) {  //能够覆盖到前面
                if (vec[i].r > r) {
                    f = true;      //找到了能够覆盖前面的区间且能够覆盖到后面的区间
                    r = vec[i].r;  //覆盖到的最右边位置
                    pos = i;       //记录区间编号
                }
            } else {
                i--;
                break;  //后面不会存在有能够覆盖左边的区间了
            }
            i++;
        }
        if (!f) {  //找不到符合要求的区间
            cout << -1 << endl;
            return;
        } else {
            ans.push_back(pos);
        }
    }
    if (r < t.length() - 1)
        cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << vec[i].id << " " << vec[i].l + 1 << endl;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}