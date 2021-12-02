#include <iostream>
using namespace std;
bool CheckYear(int year)  //判断年份是否正确
{
    if (year > 0)
        return true;
    return false;
}
bool CheckMonth(int month)  //判断月是否正确
{
    if (month >= 1 && month <= 12)
        return true;
    return false;
}
int MonthToDay(int year, int month)  //返回每个月对应的天数
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return 29;
        }
        return 28;
    } else
        return 30;
}
bool Checkday(int year, int month, int day) {  //判断天是否正确
    if (day >= 1 && day <= MonthToDay(year, month))
        return true;
    return false;
}
int main() {
    int year, month, day;
    cin >> year >> month >> day;
    if (CheckYear(year) && CheckMonth(month) && Checkday(year, month, day))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}