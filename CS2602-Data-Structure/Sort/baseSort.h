//
// Created by 黄奔皓 on 2022/11/30.
//

#ifndef 排序算法_BASESORT_H
#define 排序算法_BASESORT_H

#include "iostream"

template <class elemType>
struct Node {
    elemType data;
    Node* next;
};

template <class elemType>
struct pocketList {
    Node<elemType> *front;
    Node<elemType> *rear;
};

template <class elemType>
void pocketSort(elemType a[], int n){
    Node<elemType> *collectHead, *collectRear, *tmp; // !注意这里的初始化语法里的星号！
    pocketList<elemType> list[10];
    elemType max = 0;
    int j, k, count = 0; // count记录最大值的位数
    int base = 1;

    max = a[0];
    for(int i = 1; i < n; ++ i){
        if(a[i] > max){
            max = a[i];
        }
    }

    // *计算最大数的位数, 这里的条件别写反了！
    while(max!=0){
        count ++ ;
        max = max / 10;
    }

    // 根据数组中的元素建立单链表
    collectHead = collectRear = nullptr;
    for(int i = 0; i < n; ++ i){
        tmp = new Node<elemType>;
        tmp->data = a[i];
        tmp->next = nullptr;
        if(!collectHead){
            collectHead = tmp;
            collectRear = tmp;
        } else {
            collectRear->next = tmp;
            collectRear = tmp;
        }
    }

    for(j = 0; j < count; ++j){
        for(int i = 0; i < 10; ++ i){
            list[i].front = list[i].rear = nullptr;
        }

        while (collectHead){
            k = collectHead->data;
            k = (k / base) % 10;

            if(!list[k].front){
                list[k].front = collectHead;
                list[k].rear = collectHead;
            } else {
                list[k].rear->next = collectHead;
                list[k].rear = collectHead;
            }

            collectHead = collectHead->next;
        }

        collectHead = collectRear = nullptr;
        k = 0;
        while( k < 10){
            if(!list[k].front){
                ++ k;
                continue;
            }
            if(!collectHead){
                collectHead = list[k].front;
                collectRear = list[k].rear;
            } else {
                collectRear->next = list[k].front; // !注意这里是先让尾巴和刚进入的队列的头接，再让尾巴成为刚进入的队列的尾巴
                collectRear = list[k].rear;
            }
            ++ k;
        }
        collectRear->next = nullptr; // !不要忘了！
        base = base * 10;
    }

    for(int i = 0; i < n; ++ i){
        a[i] = collectHead->data;
        collectHead = collectHead->next;
    }
}



#endif //排序算法_BASESORT_H
