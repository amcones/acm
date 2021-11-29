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
int mp[2][300][300];
int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= 2; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> mp[k][i][j];
            }
        }
    }
    //结果的每一个点要么是0要么是1
    //如果结果的点是1，说明B和C当前点同时为1
    //且A中当前行与C中当前列同时为1的点的个数为奇
    //如果结果的点是0，说明B和C当前点至少有1个0
    //且A中当前行与C中当前列同时为1的点的个数为偶
    //A和B会限制C的可能
    return 0;
}