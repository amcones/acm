#include <iostream>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0, tmp = 0, sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G')
            cnt++, sum++;
        else
            tmp = cnt, cnt = 0;
        ans = max(ans, cnt + tmp + 1);
    }
    ans = min(ans, sum);
    cout << ans << endl;
    return 0;
}