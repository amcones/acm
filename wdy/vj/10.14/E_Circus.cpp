/***********************************
// @Author   :   amcones
// @Problem  :   E_Circus.cpp
// @When     :   2021-10-14 20:02:55
***********************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e4 + 10;
char a[maxn], c[maxn];
int t[maxn];
//每场要上n/2个人
//第一场c要和第二场a数量相同
//四种人a,b,c,d
//假设第一场各需要na,nb,nc,nd(00,01,10,11)
//那么na+nb+nc+nd=n/2
// nc+nd=b-nb+d-nd
int A, B, C, D, na, nb, nc, nd;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (c[i] == '0' && a[i] == '0')
            t[i] = 4, D++;
        if (c[i] == '1' && a[i] == '0')
            t[i] = 1, A++;
        if (c[i] == '0' && a[i] == '1')
            t[i] = 2, B++;
        if (c[i] == '1' && a[i] == '1')
            t[i] = 3, C++;
    }
    if (A > n / 2 || B > n / 2)
        return cout << -1, 0;
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= C; j++) {
            na = i, nc = j;
            nb = B + C - na - 2 * nc;
            nd = n / 2 - na - nb - nc;
            if (nb >= 0 && nb <= B && nd >= 0 && nd <= D) {
                for (int i = 1; i <= n; i++) {
                    if (t[i] == 1 && na) {
                        cout << i << ' ';
                        na--;
                    } else if (t[i] == 2 && nb) {
                        cout << i << ' ';
                        nb--;
                    }
                    if (t[i] == 3 && nc) {
                        cout << i << ' ';
                        nc--;
                    }
                    if (t[i] == 4 && nd) {
                        cout << i << ' ';
                        nd--;
                    }
                }
                return 0;
            }
        }
    }
    return cout << -1, 0;
}