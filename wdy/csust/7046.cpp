#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
//我看不懂但我大为震撼
int n, k;
int a[maxn];
//原数组严格递增，对其中一个区间加上一个数后可能会破坏原来整个数组的严格递增性
//分情况讨论，每次操作最多把数组拆成3个部分
struct node { //存每个区间的加数情况
    int l, r;
    int add;
};
vector<node> temp; //存多出来的区间
vector<node> vec; //存整个数组所有的加数情况
//保证每个区间的非严格递增性
//然后对每个区间二分去找是否有满足条件的
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = a[i] - i; //a[i]=0时就成立
    }
    vec.push_back({ 1, n, 0 });
    for (int i = 1, l, r, c; i <= k; i++) {
        scanf("%d%d%d", &l, &r, &c);
        for (int j = 0; j < vec.size(); j++) {
            node now = vec[j];
            node x, y, z;
            x = now;
            if (x.l > x.r)
                continue;
            if (l <= x.l && x.r <= r) {
                x.add += c;
            } else if (x.l <= l && r <= x.r) {
                x.r = l - 1;
                y.add = x.add + c;
                y.l = l;
                y.r = r;
                z.l = r + 1;
                z.r = now.r;
                z.add = now.add;
                if (z.r >= z.l) {
                    temp.push_back(z);
                }
                if (y.r >= y.l) {
                    temp.push_back(y);
                }
            } else if (x.r >= l && x.l < l) {
                x.r = l - 1;
                y.add = x.add + c;
                y.l = l;
                y.r = now.r;
                if (y.r >= y.l) {
                    temp.push_back(y);
                }
            } else if (x.r > r && x.l <= r) {
                x.r = r;
                x.add += c;
                y.l = r + 1;
                y.r = now.r;
                y.add = now.add;
                if (y.r >= y.l) {
                    temp.push_back(y);
                }
            }
            vec[j] = x;
        }
        for (auto x : temp) {
            vec.push_back(x);
        }
        temp.clear();
        bool flag = 0;
        for (auto x : vec) {
            if (x.l > x.r)
                continue;
            int cha = -x.add;
            if (a[x.r] < cha || a[x.l] > cha)
                continue;
            int big = *lower_bound(a + 1 + x.l - 1, a + 1 + x.r, cha);
            if (big == cha) {
                flag = 1;
                break;
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}