//
// Created by 黄奔皓 on 2022/11/9.
//

#ifndef FIND_BINARYSEARCHTREE_H
#define FIND_BINARYSEARCHTREE_H

#include <iostream>
#include "seqQueue.h"
using namespace std;
template <class elemType>
class binarySearchTree;
template <class elemType>
class Node
{
    friend class binarySearchTree<elemType>; // !是二分查找树的友元类，二分查找树可以直接用！
private:
    elemType data;
    Node *left, *right;
    int factor; // !平衡因子,用于记录左子树高度和右子树高度的差～
public:
    Node() {left=NULL; right=NULL;}
    Node(const elemType &x, Node *l=NULL, Node *r=NULL)
    { data = x; left = l; right = r; }
};

template <class elemType>
class binarySearchTree
{
private:
    Node<elemType> *root;
    bool search(const elemType &x, Node<elemType> *t) const;
    void insert(const elemType &x, Node<elemType> *&t);
    void remove(const elemType &x, Node<elemType> *&t);
public:
    binarySearchTree(){root = NULL; }
    bool search(const elemType &x) const;
    // ?两种插入方法
    void insertMethodOne(const elemType &x);
    void insertMethodTwo(const elemType &x);

    void remove(const elemType &x);
    void levelTravese() const;// !层次遍历,用于验证插入、删除操作
};

template <class elemType> // ! 递归方法
bool binarySearchTree<elemType>::search(const elemType &x, Node<elemType> *t) const
{
    if (!t) return false;
    if (x == t->data) return true;
    if (x < t->data)
        return search(x, t->left);
    else
        return search(x, t->right);
}

template <class elemType> // !非递归
bool binarySearchTree<elemType>::search(const elemType &x) const
{
    if (!root) return false;
    Node<elemType> *p;
    p = root;
    while (p)
    {   if (x == p->data) return true;
        if (x < p->data) p = p->left;
        else p = p->right;
    }
    return false;
}

template <class elemType> // !递归算法实现
void binarySearchTree<elemType>::insert(const elemType &x, Node<elemType> *&t)
{   if (!t) { t = new Node<elemType>(x); return; } // *如果没有根节点，直接插入，这些特殊情况要考虑清楚！
    if (x == t->data) return; // *已存在，结束插入
    if (x < t->data)
        insert(x, t->left);
    else
        insert(x, t->right);
}

template <class elemType> // !非递归算法实现
void binarySearchTree<elemType>::insertMethodOne(const elemType &x)
{
    Node<elemType> *p;
    if (!root)  // !如果查找树的根为空，直接建立一个结点并作为根结点
    {   root = new Node<elemType>(x);
        return;
    }
    p = root;
    while(p){
        if(p->data == x){ return;}
        if(x > p->data){
            if(p->right){
                p = p->right;
            } else {
                p->right = new Node<elemType>(x);
                return;
            }
        } else {
            if(p->left){
                p = p->left;
            } else {
                p->left = new Node<elemType>(x);
                return;
            }
        }
    }
}

template <class elemType>
void binarySearchTree<elemType>::insertMethodTwo(const elemType &x)
{
    Node<elemType> *p, *tmp, *parent=NULL;
    int flag; // !父子类型参数
    p = root;
    while (p)
    {
        if (x==p->data) return; //已存在，无需插入
        parent = p;
        if (x<p->data)
        {   flag=0;     // p is the left child of its parent
            p=p->left;
        }  // p为其父parent的左子
        else  {
            flag=1;     // p is the right child of its parent
            p=p->right;
        } //p为其父parent的右子
    }

    tmp = new Node<elemType>(x);
    if (!parent) { root = tmp; return; }   // parent为空，表示二叉树为空
    if (flag==0) parent->left = tmp;
    else  parent->right = tmp;
}




template <class elemType> // !递归算法实现
void binarySearchTree<elemType>::remove(const elemType &x, Node<elemType> *&t) // ?引用传递
{
    if (!t) return;
    if (x < t->data)
        remove(x, t->left);
    else
    if (x > t->data )
        remove(x, t->right);
    else
    {
        if (!t->left && !t->right) // *叶子结点
        {
            delete t;  // 释放待删除结点
            t = NULL;  // 父结点和叶子的链接断开
            return;
        }
        if (!t->left || !t->right) // *只有一个孩子
        {
            Node<elemType> *tmp;
            tmp = t;
            t = (t->left)? t->left : t->right;  // 父结点链接其唯一孩子结点
            delete tmp; // ?释放待删除结点对应的数据,这里用的是tmp，它和t指向同一内存区域，但是是两个不同的指针变量，不过tmp是局部的，会销毁。
            return;
        }
        // !待删除结点有两个孩子的情况 也可以找左子树的最大值
        Node<elemType> *p, *substitute;
        p = t->right;
        while (p->left) p = p->left;
        substitute = p; // ?这里的substitute是不必要的
        t->data = substitute->data;
        remove(substitute->data, t->right);
        // ?这里为啥要用递归啊，直接让指针 = NULL不行吗?
        // !回答：不行！🙅p和以t为根的右子树中最左边的结点对应的指针不是同一个变量！如果让p=NULL并不能达到预期效果！
    }
}

template <class elemType> // !非递归算法实现
void binarySearchTree<elemType>::remove(const elemType &x)
{
    if (!root) return;
    Node<elemType> *p, *parent;
    int flag; // *0为父结点顺左子下来，1为父结点顺右子下来。
    p = root; parent = NULL;
    while (p)
    {
        if ( x < p->data)
        {
            parent = p; flag = 0;
            p = p->left; continue; // !continue的好处！
        }
        if ( x > p->data)
        {
            parent = p; flag = 1;
            p = p->right; continue;
        }
        //删除开始
        if (!p->left && !p->right) // 叶子结点
        {
            delete p;
            if (!parent) {root = NULL; return;} // 待删除结点为根，且根为叶子
            if (flag == 0)// ?待删除结点为父结点的左子, 记得把指针设为NULL
                parent->left = NULL;
            else
                parent->right = NULL;
            return;
        }//叶子
        if (!p->left || !p->right) //待删除结点仅有一个孩子结点
        {
            Node<elemType> *tmp;   tmp = p;
            if (!parent) //待删除结点为根，且根有一个孩子
                root = (p->left)?p->left:p->right;
            else
            if (flag == 0)//待删除结点为父结点的左子
                parent->left = (p->left)?p->left:p->right;
            else //待删除结点为父结点的右子
                parent->right = (p->left)?p->left:p->right;
            delete tmp;     return;
        }//仅有一个孩子
        //待删除结点有二个孩子结点
        Node<elemType> *q, *substitute;
        parent = p; flag = 0;
        q = p->left;
        while (q->right) {parent = q; flag = 1; q = q->right;}
        substitute = q;
        //交换待删除结点和替身的元素值
        elemType e;    e = p->data;
        p->data = substitute->data;    substitute->data = e;
        p = substitute; //删除结点指针变为替身继续返回循环
    }//while
}

template <class elemType>
void find(const elemType x){
    node * t = 
}

#endif //FIND_BINARYSEARCHTREE_H
