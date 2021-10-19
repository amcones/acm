#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
using ll=long long;
using PLL=pair<ll,ll>;
const int maxn=1e3+10;
const int mod=1e9+7;
vector<int> e[maxn];
int f[maxn][20];
int n;
ll power(ll a,ll b,ll p)
{
    ll ans = 1;
    while(b){
        if(b&1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a,ll p)
{
    return power(a, p - 2, p);
}
int depth[maxn], fa[maxn][10];
void bfs(int s)
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(auto i:e[t]){
            if(depth[i]>depth[t]+1){
                depth[i] = depth[t] + 1;
                q.push(i);
                fa[i][0] = t;
                for (int k = 1; k <= 8;k++){
                    fa[i][k] = fa[fa[i][k - 1]][k - 1];
                }
            }
        }
    }
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
        swap(a, b);
    for (int k = 8; k >= 0;k--){
        if(depth[fa[a][k]]>=depth[b])
            a = fa[a][k];
    }
    if(a==b)
        return a;
    for (int k = 8; k >= 0;k--)
    if(fa[a][k]!=fa[b][k]){
        a = fa[a][k];
        b = fa[b][k];
    }
    return fa[a][0];
}
ll calc(int u)
{
    memset(fa, 0, sizeof fa);
    depth[u]=1;
    bfs(u);
    ll res=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int p=lca(i,j);
            res=(res+f[depth[i]-depth[p]][depth[j]-depth[p]])%mod;
        }
    }
    return res;
}
int main()
{
    cin>>n;
    int u, v;
    for (int i = 1; i < n;i++)
    {
        cin>>u>>v;
        e[u].push_back(v), e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)f[i][0]=1;
    ll tmp=inv(2,mod);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=(f[i-1][j]+f[i][j-1])%mod*tmp%mod;
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        res=(res+1LL*calc(i)*inv(n,mod)%mod)%mod;
    }
    cout<<res<<endl;
    return 0;
}