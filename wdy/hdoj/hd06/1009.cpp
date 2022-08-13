/***********************************
// @Author   :   amcones
// @Problem  :   1009.cpp
// @When     :   2022-08-04 14:54:19
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
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int maxn = 1e5 + 10;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) {
        x = _x, y = _y;
    }
};

struct Vec {
    int x, y;
    Vec(int _x, int _y) {
        x = _x, y = _y;
    }
    Vec(Point a, Point b) {
        x = a.x - b.x, y = a.y - b.y;
    }
    int operator*(Vec t) {
        return x * t.x + y * t.y;
    }
};

void init() {
}

void solve2(Point B, Point D, Point b, Point d) {
    cout << D.x << " " << d.x << endl;
    double Dd = sqrt((D.x - d.x) * (D.x - d.x) + (D.y - d.y) * (D.y - d.y));
    double Bb = sqrt((B.x - b.x) * (B.x - b.x) + (B.y - b.y) * (B.y - b.y));
    cout << Dd << ' ' << Bb << endl;
    cout << (b.x * Dd + d.x * Bb) / (Dd + Bb) << ' ';
}

void solve() {
    Point A, B, C, D, a, b, c, d;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    Vec AB = {A, B};
    Vec CD = {C, D};
    Vec Ab = {A, b};
    Vec Cd = {C, d};
    if (Ab * AB == 0)
        solve2(B, D, b, d);
    else
        solve2(A, C, a, c);
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