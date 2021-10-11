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
string s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int num[3] = {};
        for (auto i : s)
            num[i - 'A']++;
        if (num[1] == num[0] + num[2])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}