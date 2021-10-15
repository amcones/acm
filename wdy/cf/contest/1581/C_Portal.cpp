#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
//用二维前缀和干啥？？？
//枚举子矩阵的上下边
//枚举左边界，得到最优的右边界
//???
//0夹在1中间

string s[maxn];
int r[maxn][maxn], c[maxn][maxn];
int main()
{
    int t;
    cin >> t;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            r[i][j + 1] = r[i][j] + s[i][j] - '0';
            c[i + 1][j] = c[i][j] + s[i][j] - '0';
        }
    }

    return 0;
}