#include <iostream>
using namespace std;
char s[15][15];
bool win()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == 'X') {
                int u = i, v = j, sum = 0;
                while (v < 10 && s[u][v] == 'X') {
                    sum++, v++;
                }
                if (sum == 5)
                    return true;
                u = i, v = j, sum = 0;
                while (u < 10 && s[u][v] == 'X') {
                    sum++, u++;
                }
                if (sum == 5)
                    return true;
                u = i, v = j, sum = 0;
                while (u < 10 && v < 10 && s[u][v] == 'X') {
                    sum++, u++, v++;
                }
                if (sum == 5)
                    return true;
                u = i, v = j, sum = 0;
                while (u < 10 && v >= 0 && s[u][v] == 'X') {
                    sum++, u++, v--;
                }
                if (sum == 5)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    for (int i = 0; i < 10; i++)
        cin >> s[i];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (s[i][j] == 'X')
                for (int v = -1; v <= 1; v++)
                    for (int u = -1; u <= 1; u++)
                        if (i + v >= 0 && i + v < 10 && j + u >= 0 && j + u < 10 && s[i + v][j + u] == '.') {
                            s[i + v][j + u] = 'X';
                            if (win()) {
                                cout << "YES" << endl;
                                return 0;
                            }
                            s[i + v][j + u] = '.';
                        }
    cout << "NO" << endl;
    return 0;
}