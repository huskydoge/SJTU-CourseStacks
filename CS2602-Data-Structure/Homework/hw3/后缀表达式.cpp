//
// Created by 黄奔皓 on 2022/10/14.
//

#include "iostream"
#include <stack>
using namespace std;

int main(){
    char str[10000];
    stack<int> numbers;
    scanf("%s", &str);
    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    int op1, op2;

    int i = 0;
    while(str[i] != '@'){
        // 如果是数字
        int tmp = 0;
        while((str[i] >= '0') && (str[i] <= '9')){
            tmp = tmp * 10 + (str[i] - '0');
            ++ i;
        }

        if(str[i] == '.'){
            numbers.push(tmp);
            tmp = 0;
            ++ i;
        }

        while(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){

            op1 = numbers.top();
            numbers.pop();
            op2 = numbers.top();
            numbers.pop();

            switch(str[i]){
                case '*': numbers.push(op1 * op2);break;
                case '/': numbers.push(op2 / op1);break;
                case '-': numbers.push(op2 - op1);break;
                case '+': numbers.push(op2 + op1);break;
            }
            ++ i;
        }
    }
    cout << numbers.top();
}
