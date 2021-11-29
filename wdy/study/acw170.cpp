#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
using ll=long long;
using PII=pair<ll,ll>;
const int maxn = 1e2 + 10;
const int mod=1e9+7;
int n;
int p[maxn];
bool dfs(int u,int k)
{
    if(u==k)
        return p[u - 1] == n;
    bool st[maxn] = {0};
    for (int i = u - 1; i >= 0;i--){
        for (int j = i; j >= 0;j--){
            int s = p[i] + p[j];
            if(s>n||s<=p[u-1]||st[s])
                continue;
                st[s]=true;
                p[u] = s;
                if(dfs(u+1,k))return true;
        }
    }
    return false;
}
int main()
{
    p[0] = 1;
    while(cin>>n&&n)
    {
        int k = 1;
        while(!dfs(1,k))
            k++;
        for (int i = 0; i < k;i++)
            cout << p[i] << ' ';
        cout << endl;
    }
    return 0;
}