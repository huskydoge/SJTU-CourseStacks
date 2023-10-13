//
// Created by 黄奔皓 on 2022/10/12.
//

#ifndef 栈与队列_LINKQUEUE_H
#define 栈与队列_LINKQUEUE_H

class illegalSize{};
class outOfBound{};

template <class elemType>
class linkQueue;

template <class elemType>
class Node
{  friend class linkQueue<elemType>;
private:
    elemType data;
    Node *next;
public:
    Node(){next = nullptr; }
    Node(const elemType &x, Node *p = nullptr)
    { data = x; next = p;}
};

template <class elemType>
class linkQueue
{ private:
    Node<elemType> *Front, *Rear;
public:
    linkQueue(){Front = Rear = nullptr; }; //初始化链式队列，使得其为空队
    bool isEmpty() {return !Front; }; //判断队空否，空返回true，否则为false
    bool isFull(){return false; };  //判断队满否，满返回true，否则为false
    elemType front(); //读取队首元素的值，队首不变
    void enQueue(const elemType &x); //将x进队，成为新的队尾
    void deQueue(); //将队首元素出队
    ~linkQueue(); //释放队列元素所占据的动态数组
};

template <class elemType>
elemType linkQueue<elemType>::front() //读取队首元素的值，队首不变
{
    if (isEmpty()) throw outOfBound();
    return Front->data;
}


template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)  //将x进队，成为新的队尾
{  if (!Rear)
        Front = Rear = new Node<elemType>(x);
    else
    { Rear->next = new Node<elemType>(x);
        Rear = Rear->next;
    }
}

template <class elemType>
void linkQueue<elemType>::deQueue() //将队首元素出队
{   if (isEmpty()) throw outOfBound();
    Node<elemType> *tmp = Front;
    Front = Front->next;
    delete tmp;
    if (!Front) Rear = nullptr;
}

template <class elemType>
linkQueue<elemType>::~linkQueue() //释放链式栈所占空间
{  Node<elemType> *p;     p= Front;
    while (p)
    {       Front=Front->next;
        delete p;    p=Front;
    }
}

#endif //栈与队列_LINKQUEUE_H
