//
// Created by 黄奔皓 on 2022/10/14.
//
#include "iostream"
using namespace std;

class loopQueue {
    long front = 0; long rear = 0;
    long *array;
    long cnt = 0;
    long size = 0;

public:loopQueue(long s){
        array = new long[s];
        size = s;
        front = rear = 0;
    }

    void enQueue(long x){
        if(isFull()){
            doubleSpace();
        }

        array[rear] = x;
        rear = (rear + 1) % size;
        ++ cnt;
        cout << rear << ' ' << cnt << endl;
    }

    void deQueue(){
        if(rear!=front) {
            front = (front + 1) % size;
            --cnt;
        }
        cout << front << ' ' << cnt << endl;
    }

    bool isFull() const{
        return (rear + 1) % size == front;
    }

    void doubleSpace(){
        long *tmp = new long[2 * size];
        for(long i = 0; i < size - 1; ++ i){
            tmp[i] = array[i];
        }
        delete []array;
        array = tmp;
        size = 2 * size;
    }
};

int main(){
    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    long s, n;
    long op, x;
    cin >> s >> n;
    loopQueue q = loopQueue(s);
    while(n > 0){
        cin >> op;
        if(op){
            q.deQueue();
        }
        else {
            cin >> x;
            q.enQueue(x);
        }
        -- n;
    }
}
