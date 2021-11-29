#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int key[30];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, w;
        cin >> s >> w;
        for (int i = 0; i < s.length(); i++)
            key[s[i] - 'a'] = i;
        int ans = 0;
        for (int i = 0; i < w.length() - 1; i++)
        {
            ans += abs(key[w[i + 1] - 'a'] - key[w[i] - 'a']);
        }
        cout << ans << endl;
    }
    return 0;
}