//
// Created by 黄奔皓 on 2022/9/28.
//

#ifndef 线性表_POLYMONIAL_H
#define 线性表_POLYMONIAL_H

#include "../linklist.h"
using namespace std;

struct Type
{  int coef;  // 系数
    int exp;  // 幂指数
};

template <class elemType>
struct Node
{  elemType data;
    Node* next;
};

template <class elemType>
struct Polynomial
{
private:
    Node<elemType>* head;
    elemType stop_flag; // 用于判断多项式输入结束。
public:
    //从用户处获取结束标志并初始化多项式
    Polynomial(const elemType &stop);
    void getPoly(); //读入一个多项式。
    void addPoly(const Polynomial &L1, const Polynomial &L2);
    // L3=L1+l2。
    void displayPloy();//显示一个多项式
    void clear();//释放多项式空间
    ~Polynomial(){clear(); delete head;};

};

// getStop为外部函数，即非类成员函数
template <class elemType>
void getStop(elemType &stopFlag)//从用户处获取结束标志
{
    int c,e;
    cout<<"请输入系数、指数对作为结束标志,如(0,0): ";
    cin>>c>>e;
    stopFlag.coef = c;
    stopFlag.exp = e;
}

template <class elemType>
Polynomial<elemType>::Polynomial(const elemType &stop)
//初始化多项式
{   head = new Node<elemType>();
    stop_flag.coef = stop.coef;
    stop_flag.exp = stop.exp;
}
template <class elemType>
void Polynomial<elemType>::getPoly() //读入一个多项式
{   Node<elemType> *p, *tmp;
    elemType e;
    p=head;
    cout<<"请按照指数从小到大输入系数、指数对，"
    <<"最后输入结束标志对结束：\n";
    cin>>e.coef>>e.exp;
    while (true)
    {
        if ((e.coef==stop_flag.coef)&&(e.exp==stop_flag.exp)) break;
        tmp = new Node<elemType>();
        tmp->data.coef = e.coef;
        tmp->data.exp = e.exp;
        tmp->next = NULL;
        p->next = tmp;
        p=tmp;
        cin>>e.coef>>e.exp;
    }
}

template <class elemType>
void Polynomial<elemType>::addPoly(const Polynomial &La,const Polynomial &Lb){
    Node<elemType> *pa, *pb, *pc;
    Node<elemType> *tmp;
    pa = La.head->next;
    pb = Lb.head->next;
    pc = head;
    while(pa && pb){
        if(pa->data.exp == pb->data.exp) {
            if (pa->data.coef + pb->data.coef == 0) {
                pa = pa->next;
                pb = pb->next;
                continue;
            } else {
                tmp = new node<elemType>();
                tmp->data.coef = pa->data.coef + pb->data.coef;
                tmp->data.exp = pa->data.exp;
                tmp->next = nullptr;
                pa = pa->next;
                pb = pb->next;
            }
        } else if (pa->data.exp > pb->data.exp) {
            tmp = new node<elemType>();
            tmp->data.coef = pb->data.coef;
            tmp->data.exp = pb->data.exp;
            tmp->next = nullptr;
            pb = pb->next;
        } else {
            tmp = new node<elemType>();
            tmp->data.coef = pa->data.coef;
            tmp->data.exp = pa->data.exp;
            tmp->next = nullptr;
            pa = pa->next;
        }
        pc->next = tmp;
        pc = tmp;
    }


    while(pa){
        tmp = new node<elemType>();
        tmp->data.coef = pa->data.coef;
        tmp->data.exp = pa->data.exp;
        tmp->next = nullptr;
        pa = pa->next;
        pc->next = tmp;
        pc = tmp;
    }

    while(pb){
        tmp = new node<elemType>();
        tmp->data.coef = pb->data.coef;
        tmp->data.exp = pb->data.exp;
        tmp->next = nullptr;
        pb = pb->next;
        pc->next = tmp;
        pc = tmp;
    }
}// La+Lb。









#endif //线性表_POLYMONIAL_H
