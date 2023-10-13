//
// Created by 黄奔皓 on 2022/10/4.
//

#include <iostream>
#include "seqStack.h"
using namespace std;


int main()
{    // 声明一个栈。
    seqStack<char> s;
    char ctemp;
    //从键盘输入若干字符（结束用回车），
    //依照输入次序分别进栈
    cout<<"Input the elements，" << "press enter to an end: ";

    ctemp = cin.get();

    while ( ctemp!='\n')
    { 	s.push(ctemp);  ctemp = cin.get();   }

    //将栈中的结点逐个出栈，并输出到屏幕上。
    cout<<"output the elements in the stack one by one:";
    while ( !s.isEmpty() ) {
        ctemp = s.top();
        s.pop();
        cout<<ctemp;
    }
    cout<<endl;
    return 0;
}
