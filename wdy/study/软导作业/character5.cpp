#include <iostream>
#include <vector>
using namespace std;
//编写学生信息管理系统
//数据耦合：将学生类作为参数传递
//控制耦合：将控制信息作为参数传递
//特征耦合：传递整个数据结构但只使用其中一部分
class Student {
   public:
    string m_stuNumber;
    string m_stuName;
    Student(const string& stuNumber, const string& stuName, const string& phoneNumber, int Chinese, int Maths, int English) {
        m_stuNumber = stuNumber;
        m_stuName = stuName;
        m_phoneNumber = phoneNumber;
        m_Chinese = Chinese;
        m_Maths = Maths;
        m_English = English;
    }
    void Show();
    void Output() {
        cout << "Student number:" << m_stuNumber << endl;
        cout << "Student name:" << m_stuName << endl;
        cout << "Phone number:" << m_phoneNumber << endl;
        cout << "Chinese grade:" << m_Chinese << endl;
        cout << "Maths grade:" << m_Maths << endl;
        cout << "English grade:" << m_English << endl;
    }

   private:  //局部化，数据成员无法在外部被访问
    string m_phoneNumber;
    int m_Chinese;
    int m_Maths;
    int m_English;
};
vector<Student> stuData;  //存储学生数据
void Student::Show() {    //特征耦合，只使用了数据结构的一部分
    for (auto stu : stuData) {
        cout << stu.m_stuNumber << ' ' << stu.m_stuName << endl;
    }
}
void Insert() {  //功能内聚，只实现了插入新学生功能
    string stuNumber;
    string stuName;
    string phoneNumber;
    int Chinese;
    int Maths;
    int English;
    cout << "Please input student information:\n";
    cout << "Student number:\n";
    cin >> stuNumber;
    cout << "Student name:\n";
    cin >> stuName;
    cout << "Phone number:\n";
    cin >> phoneNumber;
    cout << "Chinese grade:\n";
    cin >> Chinese;
    cout << "Maths grade:\n";
    cin >> Maths;
    cout << "English grade:\n";
    cin >> English;
    Student stu = Student(stuNumber, stuName, phoneNumber, Chinese, Maths, English);
    stuData.push_back(stu);
    cout << "Insert successfully!\n";
    stu.Show();
}
void Searching(string stuNum) {  //偶然内聚，实现了输出学生数量和搜索学生两个不相关功能
    if (!stuData.empty()) {
        cout << "Student amount:" << stuData.size() << endl;
        for (auto stu : stuData) {
            if (stu.m_stuNumber == stuNum) {
                cout << "Student information found.\n";
                stu.Output();
                return;
            }
        }
        cout << "Cannot find student!\n";
    }
    cout << "Student data empty\n";
}
void Console(int oper)  //控制耦合，控制命令作为参数
{
    if (oper == 1) {
        Insert();
    } else if (oper == 2) {
        cout << "Please input student number:\n";
        string stuNumber;
        cin >> stuNumber;
        Searching(stuNumber);
    } else {
        cout << "Goodbye\n";
        exit(0);
    }
}
int main() {
    int oper;
    while (1) {
        cout << "Please input operation:\n";
        cin >> oper;
        Console(oper);
    }
    return 0;
}