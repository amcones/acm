#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int ans[6];
int mi[6] = {2, 3, 5, 7, 11, 13};
int main()
{
    string s;
    cin >> s;
    string num[2];
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            j++;
            continue;
        }
        num[j] += s[i];
    }
    for (int i = num[0].size() - 1, j = 0, z = 0; i >= 0; i--)
    {
        if (num[0][i] == ',')
        {
            j++;
            z = 0;
            continue;
        }
        ans[j] += (num[0][i] - '0') * pow(10, z);
        z++;
    }
    for (int i = num[1].size() - 1, j = 0, z = 0; i >= 0; i--)
    {
        if (num[1][i] == ',')
        {
            j++;
            z = 0;
            continue;
        }
        ans[j] += (num[1][i] - '0') * pow(10, z);
        z++;
    }
    for (int i = 0; i < 6; i++)
    {
        if (ans[i] >= mi[i])
            ans[i] -= mi[i], ans[i + 1]++;
    }
    bool f = false;
    for (int i = 6; i > 0; i--)
    {
        if (ans[i] != 0)
            f = true;
        if (f)
            cout << ans[i] << ',';
    }
    cout << ans[0];
    return 0;
}