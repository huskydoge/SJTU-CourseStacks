//
// Created by 黄奔皓 on 2022/10/4.
//
#include <iostream>
#include "linkStack.h"
using namespace std;
int main() {
    char str[20];
    linkStack<char> s;  //建立一个字符栈
    char ch;
    int i;

    cout << "Input the string: ";
    cin.getline(str, 20, '\n');
    cout << "str: " << str << endl;

    i = 0;
    ch = str[i++];
    while (ch != '\0') {
        switch (ch) {
            case '(' :
            case '{':
            case '[':
                s.push(ch);
                break;

            case ')':
                if (s.isEmpty()) {    //读入一个闭括号，栈却空，找不到匹配的开括号
                    cout << "An opening bracket '(' is expected!\n";
                    return 1;
                } else if (s.top() != '(') {
                    cout << "Wrong bracket detected!" << endl;
                    return 1;
                } else s.pop();
                break;
            case '}':
                if (s.isEmpty()) {    //读入一个闭括号，栈却空，找不到匹配的开括号
                    cout << "An opening bracket '{' is expected!\n";
                    return 1;
                } else if (s.top() != '{') {
                    cout << "Wrong bracket detected!" << endl;
                    return 1;
                } else s.pop();
                break;
            case ']':
                if (s.isEmpty()) {    //读入一个闭括号，栈却空，找不到匹配的开括号
                    cout << "An opening bracket '[' is expected!\n";
                    return 1;
                } else if (s.top() != '[') {
                    cout << "Wrong bracket detected!" << endl;
                    return 1;
                } else s.pop();
                break;
        }
        ch = str[i++];
    }
    if (!s.isEmpty()) //式子读入结束，发现栈中还有多余的开括号
    {
        cout << "A closing bracket ')' is expected!\n";
        cout << s.top() << endl;
        return 0;
    }
        cout << "No error detected!"<< endl;
    }
