#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
//肯定往最深的叶子结点逃
//A会逼迫B减少可选择的分支
vector<int> mp[maxn];
int dis1[maxn], dis2[maxn];
bool vis[maxn];
void bfs(int s, int* dis)
{
    queue<int> q;
    memset(dis, 0, sizeof dis);
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto i : mp[t]) {
            if (vis[i])
                continue;
            vis[i] = 1;
            dis[i] = dis[t] + 1;
            q.push(i);
        }
    }
}
int main()
{
    int n, x, a, b;
    cin >> n >> x;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        mp[a].push_back(b), mp[b].push_back(a);
    }
    bfs(1, dis1), bfs(x, dis2);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dis1[i] > dis2[i])
            ans = max(ans, dis1[i]);
    }
    cout << ans * 2 << endl;
    return 0;
}