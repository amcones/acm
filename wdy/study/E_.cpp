#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        double s = 0;
        for (int i = 1; i <= a; i++)
            s += log10(i);
        cout << (int)s + 1 << endl;
    }
    return 0;
}