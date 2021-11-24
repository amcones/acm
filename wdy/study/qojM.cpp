#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << max(2, (n * 2 + k - 1) / k);
    return 0;
}