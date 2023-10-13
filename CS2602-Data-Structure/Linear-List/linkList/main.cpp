//
// Created by 黄奔皓 on 2022/9/28.
//
#include <iostream>
#include "linkList.h"
using namespace std;

int main(){

    linkList<int>l = linkList<int>();
    int a[3] = {1,2,3};
    l.insert(a,3);

    l.print(); // 按顺序打印链表中的元素
    std::cout << "The first element is:" << (l.head)->next->data << std::endl << std::endl;
    std::cout << "The content of head ptr is:" << (l.head) << ",which means the address of head knot doesn't change"<< std::endl;
    std::cout << "The content of the node* next of head knot is:" << ((l.head->next)) << std::endl;

    l.reverse(); // 对链表就地逆置
    l.print();
    std::cout << "The first element is:" << (l.head)->next->data << std::endl;
    std::cout << "The content of head ptr is:" << (l.head) <<",which means the address of head knot doesn't change"<< std::endl;
    std::cout << "The content of the node* next of head knot is:" << ((l.head->next)) << std::endl;
}
