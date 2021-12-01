// Created on James的iPad.

#include <iostream>
using namespace std;
int a, b;  //瓶盖和空瓶
int ans;   //答案
int solve(int x) {
    ans += a / 4 + b / 2 + x;
    a = a % 4 + x, b = b % 2 + x;
    int y = a / 4 + b / 2;
    a %= 4, b %= 2;
    if (y > 0) {
        solve(y);
    }
    return ans;
}
int main() {
    int n;
    for (int i = 1; i <= 10; i++) {
        char chtempin[100], chtempout[100];
        sprintf(chtempin, "%d%s", i, ".in");
        sprintf(chtempout, "%d%s", i, ".out");
        freopen(chtempin, "r", stdin);
        freopen(chtempout, "w", stdout);
        a = b = ans = 0;
        cin >> n;
        int x = n / 2;
        cout << solve(x) << endl;
        fclose(stdin);
        fclose(stdout);
        cin.clear();
    }
    return 0;
}