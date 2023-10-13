//
// Created by 黄奔皓 on 2022/10/4.
//

#ifndef 栈与队列_SEQSTACK_H
#define 栈与队列_SEQSTACK_H

class illegalSize{};
class outOfBound{};

template <class elemType>
class seqStack
{  private:
    elemType *array;    //栈存储数组，存放实际的数据元素。
    int Top;            //栈顶下标。
    int maxSize;	    //栈中最多能存放的元素个数。
    void doubleSpace();
public:
    seqStack(int initSize = 100); //初始化顺序栈
    bool isEmpty () { return ( Top == -1 ); } ; //栈空返回true,否则返回false。
    bool isFull () { return (Top == maxSize-1); };//栈满返回true,否则返回false。
    elemType top ();// 返回栈顶元素的值，不改变栈顶
    void push (const elemType &e );//将元素e压入栈顶，使其成为新的栈顶。
    void pop (); //将栈顶元素弹栈。
    ~seqStack(){ delete []array;}; //释放栈占用的动态数组
};

template <class elemType>
seqStack<elemType>::seqStack(int initSize)//初始化顺序栈
{	array = new elemType[initSize];
    if (!array) throw illegalSize();
    Top=-1;    maxSize=initSize;
}

template <class elemType>
elemType seqStack<elemType>::top ()// 返回栈顶元素的值，不改变栈顶
{   if (isEmpty()) throw outOfBound();
    return array[Top];
}

template <class elemType>
void seqStack<elemType>::push(const elemType &e )
//将元素e压入栈顶，使其成为新的栈顶元素。
{     if  (isFull()) doubleSpace();
    //栈满时从新分配2倍的空间，并将原空间内容拷入
    array[++Top] = e;      	// 新结点放入新的栈顶位置。
}
template <class elemType>
void seqStack<elemType>::pop()//将栈顶元素弹栈。
{   if (Top==-1) throw outOfBound();
    Top--;
}

/*
函数initialize(seqStack)、isEmpty、isFull、top、pop、destroy（~seqStack）的时间复杂度均为O(1)。
push因某时可能扩大空间，造成O(n)时间消耗，但按照“分期付款式”法，分摊到单次的插入操作，时间复杂度仍为O(1)。
*/

template <class elemType>
void seqStack<elemType>::doubleSpace() {
    elemType *tmp = new elemType[2*maxSize];
    if (!tmp) throw illegalSize();
    for(int i=0; i < maxSize; i++){
        tmp[i] = array[i];
    }
    delete[] array;
    array = tmp;
    maxSize = 2 * maxSize;

}



#endif //栈与队列_SEQSTACK_H
