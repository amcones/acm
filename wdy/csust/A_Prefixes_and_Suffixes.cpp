#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
pair<string, int> a[205];
const int maxn = 1e5 + 10;
bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.first.length() < b.first.length();
}
string c;
int n;
void solve()
{
    int num[205] = {};
    char ans[205];
    bool flag = true;
    for (int i = 1; i <= n * 2 - 2; i++) {
        flag = true;
        for (int j = 0; j < a[i].first.length(); j++) {
            if (a[i].first[j] != c[j]) {
                flag = false;
                break;
            }
        }
        if (flag && num[a[i].first.length()] == 0) {
            num[a[i].first.length()] = 1;
            ans[a[i].second] = 'P';
            continue;
        }
        flag = true;
        for (int j = 0; j < a[i].first.length(); j++) {
            if (a[i].first[j] != c[j + c.length() - a[i].first.length()]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans[a[i].second] = 'S';
            continue;
        } else
            return;
    }
    for (int i = 1; i <= 2 * n - 2; i++)
        cout << ans[i];
    exit(0);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= 2 * n - 2; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + 2 * n - 2, cmp);
    for (int i = 1; i <= 2; i++)
        for (int j = 2 * n - 3; j <= 2 * n - 2; j++) {
            c += a[i].first + a[j].first;
            solve();
            c.clear();
        }
    return 0;
}