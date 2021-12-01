#include <iostream>
#include "testlib.h"
using namespace std;
const int maxn = 5e2 + 10;
char ch[3] = {'.', '#', 'G'};
char mp[maxn][maxn];
void YES() {
    quitf(_ok, "The ans is correct.");
}
void NO() {
    quitf(_wa, "The ans is not correct.");
    exit(0);
}
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 100; i++) {
        startTest(i);
        char chtempin[100];
        int n = rnd.next(1, 500);
        int m = rnd.next(1, 500);
        cout << n << ' ' << m << endl;
        int sx = rnd.next(1, n), sy = rnd.next(1, m);
        mp[sx][sy] = 'U';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == sx && j == sy)
                    continue;
                mp[i][j] = ch[rnd.wnext(3, 0)];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << mp[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}