//
// Created by 黄奔皓 on 2022/10/15.
//
#include <stack>
#include "iostream"
using namespace std;

class Queue {
public:
    long front = 0; long rear = 0;
    long *array;
    long cnt = 0;
    long size = 0;
    Queue(long s){
        array = new long[s + 1];
        size = s + 1;
        front = rear = 0;
    }

    void enQueue(long x){
        array[rear] = x;
        rear = (rear + 1) % size;
    }

    void deQueue(){
        if(rear!=front) {
            front = (front + 1) % size;
            --cnt;
        }
    }

    bool empty() const {
        return (rear == front);
    }
};

bool check(Queue &q)
{
    stack<long> s; //模拟栈
    long n = q.size;
    for(long i = 1; i < n; i++)
    {
        s.push(i); //元素入栈
        //栈非空且栈顶元素等于队头元素，说明该元素需要出栈
        while(!s.empty() && s.top() == q.array[q.front])
        {
            s.pop(); q.deQueue();
        }
    }
    return s.empty() ? true : false;

}

int main()
{
    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    int T;
    cin >> T;
    long number = 0;
    long n;

    while(T > 0) {
        cin >> n;
        Queue q = Queue(n);
        for(int i = 0; i < n ; ++ i){
            cin >> number;
            q.enQueue(number);
        }


        if(check(q)) cout << "Yes" << endl;
        else cout << "No" << endl;

        while(!q.empty()) q.deQueue();
        -- T;
    }
}

