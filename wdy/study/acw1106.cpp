/***********************************
// @Author   :   amcones
// @Version  :   1.0
// @Problem  :   acw1106.cpp
// @When     :   2021-10-11 18:40:02
***********************************/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLL=pair<ll,ll>;
const int maxn=1e5+10;
int g[1100][1100];
bool st[1100][1100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cin >> g[i][j];
    
    return 0;
}