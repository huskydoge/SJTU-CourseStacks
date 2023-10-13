//
// Created by 黄奔皓 on 2022/10/12.
//

#ifndef 栈与队列_SEQQUEUE_H
#define 栈与队列_SEQQUEUE_H

class illegalSize{};
class outOfBound{};


// Rear 指向实际队尾的后一个位置，所以如果空间为n，那么最多存储 n - 1 个元素
template<class elemType>
class seqQueue{
private:
    elemType *array;
    int maxSize;
    int Front, Rear;
    void doubleSpace();
public:
    seqQueue(int size=10); //初始化队列元素的存储空间
    bool isEmpty(); //判断队空否，空返回true，否则为false
    bool isFull();  //判断队满否，满返回true，否则为false
    elemType front(); //读取队首元素的值，队首不变
    void enQueue(const elemType &x); //将x进队，成为新的队尾
    void deQueue(); //将队首元素出队
    ~seqQueue(); //释放队列元素所占据的动态数组

};

template <class elemType>
seqQueue<elemType>::seqQueue(int size) //初始化队列元素的存储空间
{
    array = new elemType[size]; //申请实际的队列存储空间
    if (!array) throw illegalSize();
    maxSize = size;
    Front = Rear = 0;
}

template <class elemType>
bool seqQueue<elemType>::isEmpty()  //判断队空否，空返回true，否则为false
{return Front == Rear;}

template <class elemType>
bool seqQueue<elemType>::isFull() //判断队满否，满返回true，否则为false
{return (Rear + 1) % maxSize == Front;}

template <class elemType>
elemType seqQueue<elemType>::front() //读取队首元素的值，队首不变
{    if (isEmpty()) throw outOfBound();
    return array[Front];
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)  //将x进队，成为新的队尾
{  if (isFull())  doubleSpace();
    array[Rear]=x;
    Rear = (Rear+1) % maxSize;
}
template <class elemType>
void seqQueue<elemType>::deQueue() //将队首元素出队
{  if (isEmpty()) throw outOfBound();
    Front = (Front+1) % maxSize;
}


#endif //栈与队列_SEQQUEUE_H
