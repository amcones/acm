/***********************************
// @Author   :   amcones
// @Problem  :   1008.cpp
// @When     :   2022-07-26 19:10:24
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
const int maxn = 2e2 + 10;

struct pot {
    int x, y, z;
    pot() {}
    pot(int _x, int _y, int _z) { x = _x, y = _y, z = _z; }
    bool operator==(pot b) const {
        return x == b.x && y == b.y && z == b.z;
    }
    pot operator-(const pot& p) const { return pot(x - p.x, y - p.y, z - p.z); }
    pot operator*(const pot& p) const { return pot(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); }
    int operator^(const pot& p) const { return x * p.x + y * p.y + z * p.z; }
};
inline int ptoplane(const pot& a, const pot& b, const pot& c, const pot& p) {
    return ((b - a) * (c - a)) ^ (p - a);  //点到平面上一点的向量在平面法向量上的投影
}
inline bool colinear(const pot& a, const pot& b, const pot& p) {
    pot t = (a - b) * (b - p);
    return !t.x && !t.y && !t.z;
}
struct segment {
    pot sp, tp;
};

void init() {
}
void solve() {
    int n;
    cin >> n;
    vector<pot> p;
    vector<segment> seg(n);
    for (auto& i : seg) {
        cin >> i.sp.x >> i.sp.y >> i.sp.z >> i.tp.x >> i.tp.y >> i.tp.z;
        p.push_back({i.sp.x, i.sp.y, i.sp.z});
        p.push_back({i.tp.x, i.tp.y, i.tp.z});
    }
    int ans = 1;
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            if (p[i] == p[j])
                continue;
            for (int k = j + 1; k < p.size(); k++) {
                if (p[i] == p[k] || p[j] == p[k])
                    continue;
                if (colinear(p[i], p[j], p[k]))
                    continue;
                int tmp = 0;
                //枚举三个点得到平面方程
                //如果三点共线则跳过
                for (int s = 0; s < seg.size(); s++) {
                    int x = ptoplane(p[i], p[j], p[k], seg[s].sp);
                    int y = ptoplane(p[i], p[j], p[k], seg[s].tp);
                    if (!x || !y || (x < 0 && y > 0) || (x > 0 && y < 0))
                        tmp++;
                }
                ans = max(ans, tmp);
            }
            //特判所有点共线
            int tmp = 0;
            for (int s = 0; s < seg.size(); s++) {
                if (colinear(p[i], p[j], seg[s].sp) || colinear(p[i], p[j], seg[s].tp))
                    tmp++;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}