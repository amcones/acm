#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 20;
vector<int> edge[N];
int s[N], top = 0;  // stl里的stack没办法遍历，所以用数组模拟
bool instack[N];
int cnt = 0;

void dfs(int u) {
    s[top++] = u;
    instack[u] = true;
    for (int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if (!instack[v])
            dfs(v);
        else {
            ++cnt;
            int t;
            for (t = top; s[t] != v; t--)
                ;
            // for (int i = t; i < top; i++)
            // cout << s[i] << " ";
            // cout << endl;
        }
    }
    top--;  //回溯
    instack[u] = false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        memset(instack, -1, sizeof instack);
        for (int i = 0; i < N; i++)
            vector<int>().swap(edge[i]);
        int n, m, u, v;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1);
        cout << cnt << endl;
    }
    return 0;
}