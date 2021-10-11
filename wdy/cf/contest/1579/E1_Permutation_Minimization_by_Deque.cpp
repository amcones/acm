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
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n;
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            cin >> p;
            if (q.empty() || p < q.front())
                q.push_front(p);
            else
                q.push_back(p);
        }
        for (auto i : q)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}