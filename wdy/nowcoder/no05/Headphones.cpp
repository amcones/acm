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

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    n -= k;
    if (n <= k)
        cout << -1;
    else
        cout << n + k + 1;
    return 0;
}