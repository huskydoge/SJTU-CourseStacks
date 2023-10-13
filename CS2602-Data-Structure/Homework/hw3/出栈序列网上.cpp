//
// Created by 黄奔皓 on 2022/10/14.
//
#include<iostream>
#include <queue>
#include <stack>
using namespace std;

bool check(queue<long> &q)
{
    stack<long> s; //模拟栈
    long n = q.size();
    for(long i = 1; i <= n; i++)
    {
        s.push(i); //元素入栈
        //栈非空且栈顶元素等于队头元素，说明该元素需要出栈
        while(!s.empty() && s.top() == q.front())
        {
            s.pop(); q.pop();
        }
    }
    return s.empty() ? true : false;

}

int main()
{
    queue<long> Queue;
    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    int T;
    cin >> T;
    long number = 0;
    long n;

    while(T > 0) {
        cin >> n;
        for(int i = 0; i < n ; ++ i){
            cin >> number;
            Queue.push(number);
        }

        if(check(Queue)) cout << "Yes" << endl;
        else cout << "No" << endl;

        while(!Queue.empty()) Queue.pop();
        -- T;
    }
}
