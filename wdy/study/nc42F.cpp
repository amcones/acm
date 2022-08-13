/***********************************
// @Author   :   amcones
// @Problem  :   nc42F.cpp
// @When     :   2021-12-18 11:59:31
***********************************/
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<numeric>
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLL=pair<ll,ll>;
const int maxn=1e5+10;
bool st[maxn];
vector<int> prime;
void euler(int n)
{
    for(int i=2;i<=n;i++){
        if(!st[i])prime.push_back(i);
        for(auto j:prime){
            if(j*i>n)break;
            st[j*i]=1;
            if(i%j==0)break;
        }
    }
}
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int main()
{
    
    return 0;
}