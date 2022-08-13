/***********************************
// @Author   :   amcones
// @Problem  :   A_B_Problem_Plus.cpp
// @When     :   2022-08-04 10:39:26
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
const int maxn = 2e5 + 10;
const double PI = acos(-1);
int rev[maxn];

struct Complex {
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0) {
        x = _x, y = _y;
    }
    Complex operator-(const Complex& b) const {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator+(const Complex& b) const {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator*(const Complex& b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

void change(Complex y[], int len) {
    for (int i = 0; i < len; ++i) {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) {  // 如果最后一位是 1，则翻转成 len/2
            rev[i] |= len >> 1;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (i < rev[i]) {  // 保证每对数只翻转一次
            swap(y[i], y[rev[i]]);
        }
    }
    return;
}

void fft(Complex y[], int len, int on) {
    change(y, len);  //先进行蝴蝶变换，把数据都移动到最终位置
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));  //单位根
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);

            for (int k = j; k < j + h / 2; k++) {
                Complex u = y[k], t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < len; i++) {
            y[i].x /= len;
        }
    }
}
void init() {
}
void solve() {
}
int sum[maxn];
Complex x1[maxn], x2[maxn];
int main() {
    string a, b;
    while (cin >> a >> b) {
        int len1 = a.length(), len2 = b.length();
        int len = 1;
        while (len < max(len1 * 2, len2 * 2))
            len <<= 1;
        for (int i = 0; i < len; i++) {
            if (i < len1)
                x1[i] = Complex(a[len1 - 1 - i] - '0', 0);
            else
                x1[i] = Complex(0, 0);
            if (i < len2)
                x2[i] = Complex(b[len2 - 1 - i] - '0', 0);
            else
                x2[i] = Complex(0, 0);
        }
        fft(x1, len, 1), fft(x2, len, 1);
        for (int i = 0; i < len; i++)
            x1[i] = x1[i] * x2[i];
        fft(x1, len, -1);
        for (int i = 0; i < len; i++) {
            sum[i] = int(x1[i].x + 0.5);
        }
        for (int i = 0; i < len; i++) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        len = len1 + len2 - 1;
        while (sum[len] == 0 && len > 0)
            len--;
        for (int i = len; i >= 0; i--)
            cout << sum[i];
        cout << '\n';
    }
    return 0;
}