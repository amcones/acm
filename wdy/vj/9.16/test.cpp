#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> q;  //定义队列
stack<int> s;  //定义栈
int main() {
    if (q.empty())              //判断队列是否为空
        q.push(5), q.push(9);   //向队列中先后加入5和9
    cout << q.front() << endl;  //返回队首的值
    q.pop();                    //删除队首元素（出队）
    //////////////////////////////栈是类似的
    if (s.empty())             //判断栈是否为空
        s.push(5), s.push(9);  //向栈中先后加入5和9
    cout << s.top() << endl;   //返回栈顶的值
    s.pop();                   //删除栈顶元素（出栈）
    return 0;
}