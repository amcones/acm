#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string ans;
            for (int j = 0; j < i; j++) {
                ans += '(', ans += ')';
            }
            int len = 2 * n - i * 2;
            for (int j = 0; j < len / 2; j++)
                ans += '(';
            for (int j = 0; j < len / 2; j++)
                ans += ')';
            cout << ans << endl;
        }
    }
    return 0;
}