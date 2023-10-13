//
// Created by 黄奔皓 on 2022/9/28.
//

#ifndef 线性表_LINKLIST_H
#define 线性表_LINKLIST_H
#include "iostream"
class outOfBound{};

template <class elemType> // 别忘了写模版声明
class linkList; //类的前向说明，解决类之间的交叉引用问题

template <class elemType>
class node
{   friend class linkList<elemType>; //友元类，linklist类可以访问node类中的private和protect的元素！
private:
//    elemType data;
//    node *next;
public:
    elemType data;
    node *next;
    node():next(nullptr){};
    node(const elemType &e, node *N=nullptr)
    {  data = e; next = N; };
};


template <class elemType>
class linkList
{
private:

public:
    node<elemType> *head;
    linkList();  //构造函数，建立一个空表
    bool isEmpty ()const; //表为空返回true,否则返回false。
    bool isFull ()const {return false;}; //表为满返回true,否则返回false。
    int length ()const;  //表的长度
    elemType get(int i)const;//返回第i个元素的值
    //返回值等于e的元素的序号，从第1个开始，无则返回0.
    int find (const elemType &e )const;
    //在第i个位置上插入新的元素（值为e）。
    void insert (int i, const elemType &e );
    void insert(const elemType a[], int n);
    //若第i个元素存在，删除并将其值放入e指向的空间。
    void remove (int i, elemType &e);
    void reverse() const; //元素就地逆置
    void clear (); //清空表，使其为空表
    void print (char s[]="printing") const{
        int n = this->length();
        if(s) {
            std::cout << s << std::endl;
        }
        for(int i = 1; i <= n; ++ i){
            std::cout << this->get(i) << std::endl;
        }
        std::cout << "Done!" << std::endl << std::endl;
    }
    ~linkList();

};

template <class elemType>
linkList<elemType>::~linkList() {
    node<elemType> *p, *q;
    p = head->next;
    head->next = nullptr;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    p = nullptr;
    q = nullptr;
}

template <class elemType>
linkList<elemType>::linkList() //构造函数，建立一个空表
{
    head = new node<elemType>(); // 这里有没有括号没区别：https://blog.csdn.net/spaceyqy/article/details/22730939
}

template <class elemType>
bool linkList<elemType>::isEmpty ()const //表为空返回true,否则返回false。
{
    if (head->next==nullptr) return true;
    return false;
}

template <class elemType>
void linkList<elemType>::insert (int i, const elemType &e )
//在第i个位置上插入新的元素（值为e）。
{   if (i<1) return;//参数i越界
    int j=0; node<elemType>  *p=head; // 从头节点开始！

    while (p&&j<i-1)
    {  j++;  p=p->next; }

    if (!p) return; //参数i越界

    p->next = new node<elemType>(e, p->next);
}

template <class elemType>
int linkList<elemType>::length ()const //表的长度
{
    int count=0;
    node<elemType> *p;
    p=head->next;
    while(p)
    {   count++;    p=p->next;  }
    return count;
}

template <class elemType>  //注意：五步口诀法
elemType linkList<elemType>::get(int i )const
//返回第i个元素的值,首元素为第1个元素
{
    if (i<1) throw outOfBound();
    int j=1;
    node<elemType> *p = head->next;
    while (p&&j<i) {p=p->next; j++;}
    if (p) return p->data;
    throw outOfBound();
}

template <class elemType>
int linkList<elemType>::find (const elemType &e )const
//返回值等于e的元素的序号，从第1个开始，无则返回0.
{   int i=1;
    node<elemType> *p = head->next;
    while (p)
    {   if (p->data==e) break;
        i++;   p=p->next;
    }
    if (p) return i; // 如果是nulptr意味着没有找到
    return 0;   }

template <class elemType>    //P、Q兄弟协同法
void linkList<elemType>::clear () //清空表，使其为空表
{    node<elemType> *p,*q;
    p = head->next;
    head->next = nullptr;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
}

//最速插入位置—脖子//首席插入法
template <class elemType>
void linkList<elemType>:: insert(const elemType a[], int n)
{   node<elemType> *tmp;
    for (int i=0; i<n; i++)
    {     tmp = new node<elemType>(a[i], head->next);
            head->next = tmp;
    }
}


template <class elemType>
void linkList<elemType>::reverse() const
{   node<elemType> *p,*q;  //兄弟俩协同
    p = head->next;
    head->next = nullptr; // 让头节点先跑到队伍尾部
    while (p)
    {   q = p->next; // 让q为头节点之后的元素的下一个元素（下一个处理的元素）
        p->next = head->next; // head退位给p  head->null ---->  head->p-null
        head->next = p; //首席插入
        p=q;
    }
}






#endif //线性表_LINKLIST_H
