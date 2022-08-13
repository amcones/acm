#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
#define endl '\n'

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<long long, int> PLI;
typedef pair<string, string> PSS;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int mod = 998244353;

int seed;
uniform_int_distribution<> u(1, 400);
mt19937 rng(seed);

int n, q;
struct node {
    int a, b, c;
} a[15][N];
int num[15], dp[15][405][405];
LL ans;

bool cmp(node x, node y) {
    if (x.a != y.a)
        return x.a < y.a;
    if (x.b != y.b)
        return x.b < y.b;
    return x.c < y.c;
}

int solve(int IQ, int EQ, int AQ) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][IQ][EQ] <= AQ)
            res++;
    }
    return res;
}

LL power[2000005];

void init() {
    power[0] = 1;
    for (int i = 1; i <= q; i++) {
        power[i] = power[i - 1] * seed % mod;
    }
    int lastans = 0;
    for (int i = 1; i <= q; i++) {
        int IQ = (u(rng) ^ lastans) % 400 + 1;  // The IQ of the i-th friend
        int EQ = (u(rng) ^ lastans) % 400 + 1;  // The EQ of the i-th friend
        int AQ = (u(rng) ^ lastans) % 400 + 1;  // The AQ of the i-th friend
        lastans = solve(IQ, EQ, AQ);
        (ans += lastans * power[q - i]) %= mod;
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++)
            cin >> a[i][j].a >> a[i][j].b >> a[i][j].c;
        sort(a[i] + 1, a[i] + 1 + num[i], cmp);
        int cnt = 0;
        memset(dp[i], inf, sizeof dp[i]);
        for (int j = 1; j <= num[i]; j++) {
            if (a[i][j].a == a[i][cnt].a && a[i][j].b == a[i][cnt].b)
                continue;
            else {
                a[i][++cnt] = a[i][j];
                dp[i][a[i][cnt].a][a[i][cnt].b] = a[i][cnt].c;
            }
        }
        num[i] = cnt;
        for (int x = 1; x <= 400; x++)
            for (int y = 1; y <= 400; y++)
                dp[i][x][y] = min(dp[i][x][y], min(dp[i][x - 1][y], dp[i][x][y - 1]));
    }
    cin >> seed;
    init();
    cout << ans;
    return 0;
}