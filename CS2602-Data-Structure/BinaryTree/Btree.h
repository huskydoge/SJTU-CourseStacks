#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <iostream>
#include "seqStack.h"
#include "seqQueue.h"
using namespace std;
//BTree类的前向说明
template <class elemType>
class BTree;

template <class elemType>
class Node
{   friend class BTree<elemType>;
private:
    elemType data;       Node *left, *right;
    int leftFlag;  // 用于标识是否线索，0时left为左孩子结点，1时为前驱线索
    int rightFlag; // 用于标识是否线索，0时right为右孩子结点，1时为后继线索
public:
    Node(){left=NULL; right=NULL; leftFlag = 0; rightFlag=0;};
    Node(const elemType &e, Node* L=NULL, Node *R=NULL)
    {  data = e;
        left=L; right=R; leftFlag = 0; rightFlag=0;
    };
};

template <class elemType>
class BTree
{
private:
    Node<elemType> *root;
    elemType stopFlag;
    int Size (Node<elemType> *t); // 求以t为根的二叉树的结点个数。
    int Height (Node<elemType> *t); // 求以t为根的二叉树的高度。
    void DelTree(Node<elemType> *t);// 删除以t为根的二叉树
    // 递归形式
    void PreOrder(Node<elemType> *t);
    // 按前序遍历输出以t为根的二叉树的结点的数据值
    void InOrder(Node<elemType> *t);
    // 按中序遍历输出以t为根的二叉树的结点的数据值
    void PostOrder(Node<elemType> *t);
    // 按后序遍历输出以t为根的二叉树的结点的数据值
public:
    BTree(){root=NULL;}
    void createTree(const elemType &flag);//创建一棵二叉树
    bool isEmpty () { return (root == NULL);}// 二叉树为空返回true，否则返回false
    Node<elemType> * GetRoot(){ return  root; }
    int Size (); //求二叉树的结点个数。
    int Height (); //求二叉树的高度。
    void DelTree();//删除二叉树
    void PreOrder();// 按前序遍历输出二叉树的结点的数据值
    void InOrder();// 按中序遍历输出二叉树的结点的数据值
    void PostOrder();// 按后序遍历输出二叉树的结点的数据值
    void LevelOrder();// 按中序遍历输出二叉树的结点的数据值
    // ! 线索树
    Node<elemType> * ThreadMid();
    void ThreadMidVisit(Node<elemType> *first);
    void ThreadMidPreVisit();
    // ! 中序遍历和前序遍历序列给定，求树
    Node<elemType> * buildTree(elemType pre[], int pl, int pr, elemType mid[], int ml, int mr);
    // ! 表达式树
    int priOver(const char ch1, const char ch2);
    void buildExpTree(const char *exp);
    int calExpTree();


};

// *中序线索树，左子为空则指向直接前继，右子为空则指向直接后继
template<class elemType>
Node<elemType> * BTree<elemType> ::ThreadMid() {
    Node<elemType> *first;
    if (!root) return first = NULL;
    seqStack<Node<elemType> *> s1; // 节点存储栈
    seqStack<int> s2; // 辅助栈
    Node<elemType> *p, *pre;
    int flag, zero = 0, one = 1;
    pre = NULL;
    first = NULL;
    s1.push(root);
    s2.push(zero);

    while (!s1.isEmpty()) {
        flag = s2.top();
        s2.pop();
        p = s1.top(); //读取栈顶元素
        if (flag == 1) {
            s1.pop();
            if (!first) first = p;
            if (p->right)
                //有右子压右子，没有进入下一轮循环
            {
                s1.push(p->right);
                s2.push(zero);
            }
            // 加中序遍历线索
            if (!p->left) {
                p->leftFlag = 1;
                p->left = pre;
            }
            if (pre && (!pre->right)) { // ? 除了要设置 p 的线索，别忘了 pre的线索也要设置，因为 p 被pop掉了，pre也要变！
                pre->rightFlag = 1;
                pre->right = p;
            }
            pre = p;
        } else {
            s2.push(one); // ? 走过这个点就要变成 one！
            if (p->left)
                //有左子压左子
            {
                s1.push(p->left);
                s2.push(zero);
            }
        }
    }
    // 遍历序列中最后一个结点后继为空
    p->rightFlag = 1;
    cout << p->data << " next: "<< "NULL" << endl;

    return first;
}

// *中序搜索树用于中序遍历
template <class elemType>
void BTree<elemType>::ThreadMidVisit( Node<elemType> *first)
{
    if (!first) return;
    Node<elemType> *p;   p = first;
    while (p)
    {   cout<<p->data;
        //找p的后继元素
        if (p->rightFlag==0) //如果有右子
        {  p = p->right;
            //沿右子的左分支一路向左
            while ((p->leftFlag==0)&& p->left)
                p = p->left;
        }
        else p = p->right; //无右子直接用后继线索
    }
    cout << endl;

}

// * 中序搜索树用于前序遍历
template <class elemType>
void BTree<elemType>::ThreadMidPreVisit()
{
    Node<elemType> *p;    p = root;
    while (p)
    {  cout<<p->data;
        if (p->leftFlag==0)  p = p->left;
        else
        {   if (p->rightFlag==0)   p = p->right;
            else
            {
                while (p&&(p->rightFlag==1))
                    p = p->right; // * 其实是找到当前节点的父亲节点
                if (!p) return;
                p = p->right;
            }
        }
    }
    cout<<endl;
}

template <class elemType>
Node<elemType> *BTree<elemType>::buildTree(elemType pre[], int pl, int pr, elemType mid[], int ml, int mr)
//! pre数组存储了前序遍历序列，pl为序列左边界下标，pr为序列右边界下标。
//! mid数组存储了中序遍历序列，ml为序列左边界下标，mr为序列右边界下标。
{  Node<elemType> *p, *leftRoot, *rightRoot;
    int i, pos, num;
    int lpl, lpr, lml, lmr; // *左子树中前序的左右边界、中序的左右边界
    int rpl, rpr, rml, rmr; // *右子树中前序的左右边界、中序的左右边界
    if (pl>pr) return NULL;
    p = new Node<elemType>(pre[pl]); // *找到子树的根并创建结点
    if (!root) root = p;
    // *找根在中序中的位置和左子树中结点个数
    for (i=ml; i<=mr; i++)
        if (mid[i]==pre[pl]) break;
    pos = i;    // *子树根在中序中的下标
    num = pos-ml; // *子树根的左子树中结点的个数

    //找左子树的前序、中序序列下标范围
    lpl = pl+1; lpr = pl+num;
    lml = ml; lmr = pos-1;
    leftRoot = buildTree(pre, lpl, lpr, mid, lml, lmr);
    //找右子树的前序、中序序列下标范围
    rpl = pl+num+1; rpr = pr;
    rml = pos+1; rmr = mr;
    rightRoot = buildTree(pre, rpl, rpr, mid, rml, rmr);
    p->left = leftRoot;
    p->right = rightRoot;
    return p;
}

// *******表达式树********

template <class elemType>
int BTree<elemType>::priOver(const char ch1, const char ch2)
// *比较操作符优先级的函数，ch1为新读入操作符，ch2为操作符栈栈顶操作符
//当ch1优先级比ch2高，函数返回1; 低,返回-1；相同，返回0
{
    switch (ch1)
    {  case '(': return 1; // 左括号优先级在栈外是最高
        case ')': if (ch2!='(') return -1;
                //右括号和栈顶四则运算操作符比，总是优先级最低
            else return 0; //右括号和栈顶的左括号比，优先级一样
        case '*':
        case '/': if ((ch2=='*') || (ch2=='/')) return -1; //相同运算，栈中优先级高
            else return 1; //只要栈顶不是乘除，优先级肯定比栈顶操作符高
        case '+':
        case '-': //只要栈顶不是hash和左括号，都比栈顶优先级高
            if ((ch2 =='#')||(ch2 == '(')) return 1;
            else   return -1;
    };
}

// 根据一个表达式字符串建立表达式树2
template <class elemType>
void BTree<elemType>::buildExpTree(const char *exp)
{
    seqStack<char> opStack; //操作符栈
    seqStack<Node<elemType>*> subTStack;//子树栈

    Node<elemType> *p, *left, *right;
    char hash = '#', ch;
    opStack.push(hash);
    while (*exp)
    {
        if ((*exp>='0')&&(*exp<='9'))
            //读入数字
        {
            p = new Node<elemType> (*exp);
            subTStack.push(p);
        }
        else //读入操作符（包括括号）
        {
            ch = opStack.top(); //读opStack栈顶

            //将opStack栈顶所有比新读入操作符优先级高的弹出来处理
            while (priOver(*exp,ch)==-1)
            {
                opStack.pop(); //opStack栈顶出栈
                right = subTStack.top(); subTStack.pop();
                left  = subTStack.top(); subTStack.pop();
                p = new Node<elemType> (ch, left, right);
                //构建新操作数结点

                subTStack.push(p); //新操作数压栈
                ch = opStack.top();
            }
            // 当前opStack栈顶不比新读入的操作符优先级高
            if (priOver(*exp,ch)==0)
                //优先级一样，即分别为右左括号
                opStack.pop(); //左括号弹出扔掉即可。
            else opStack.push(*exp); //opStack栈顶
            //操作符比新读入的操作符优先级低，
            //新读入操作符直接压栈
        };
        exp++;
    }
    //将opStack栈中所有操作符弹空
    ch = opStack.top();
    while (ch!='#')
    {
        opStack.pop();
        right = subTStack.top(); subTStack.pop();
        left  = subTStack.top(); subTStack.pop();
        p = new Node<elemType>(ch, left, right);
        subTStack.push(p);
        ch = opStack.top();
    }
    //操作数栈numStack中剩余的唯一的
    //元素即二叉树的根
    root = subTStack.top(); subTStack.pop();
}

//用后序遍历方法计算一个表达式树的值
template <class elemType>
int BTree<elemType>::calExpTree()
{
    //后序遍历
    if (!root) return 0;
    Node<elemType> *p;
    seqStack<Node<elemType> *> s1;
    seqStack<int> s2; // 辅助栈
    seqStack<int> numStack;
    int zero=0, one=1, two=2;
    int flag, num, num1, num2;
    s1.push(root); s2.push(zero);
    while (!s1.isEmpty())
    {
        flag = s2.top(); s2.pop();
        p = s1.top();
        switch(flag)
        {
            case 2:
                s1.pop();
                //cout << p->data;
                //访问结点时，开始处理：
                //见数字压数字栈，见操作符弹
                //两数字计算，计算结果压数字栈
                if ((p->data>='0')&&(p->data<='9'))
                {
                    num = p->data-'0';
                    numStack.push(num);
                }
                else
                {   num2 = numStack.top(); numStack.pop();
                    num1 = numStack.top(); numStack.pop();
                    switch (p->data)
                    {
                        case '+': num = num1+num2; break;
                        case '-': num = num1-num2; break;
                        case '*': num = num1*num2; break;
                        case '/': num = num1/num2; break;
                    };
                    numStack.push(num);
                }
                break;
            case 1:   s2.push(two);
                if (p->right)
                {
                    s1.push(p->right);
                    s2.push(zero);
                }
                break;
            case 0:   s2.push(one);
                if (p->left)
                {
                    s1.push(p->left);
                    s2.push(zero);
                }
                break;
        };// switch
    }// while
    // get the result of the expression tree
    num = numStack.top(); numStack.pop();
    return num;
}

template <class elemType>
void BTree<elemType>::createTree(const elemType &flag)
//创建一棵二叉树
{  seqQueue<Node<elemType>*> que;
    elemType e, el, er;     // 根，左孩子，右孩子
    Node<elemType> *p, *pl, *pr;
    stopFlag = flag;
    cout << "Please input the root: ";
    cin >> e;
    if (e==flag) { root = NULL; return;}

    p = new Node<elemType>(e);
    root = p; //根结点为该新创建结点
    que.enQueue(p);

    while (!que.isEmpty())
    {   p = que.front();  //获得队首元素并出队
        que.deQueue();
        cout<<"Please input the left child and the right child of "<<p->data
                    <<" using "<<flag<<" as no child: ";
        cin >> el >> er;
        if (el!=flag) //该结点有左孩子
        {     pl = new Node<elemType>(el);
              p->left = pl;
              que.enQueue(pl);
        }
        if (er!=flag) //该结点有右孩子
        {   pr = new Node<elemType>(er);
            p->right = pr;
            que.enQueue(pr);
        }
    }
}

template <class elemType>   // 公有
int BTree<elemType>::Size()
{ return Size(root); }

template <class elemType>  // 私有
int BTree<elemType>::Size (Node<elemType> *t)
//得到以t为根二叉树结点个数，递归算法实现。
{  if (!t) return 0;
    return 1+Size(t->left)+Size(t->right);    }

template <class elemType>
int BTree<elemType>::Height()
{ return Height(root); }

template <class elemType>
int BTree<elemType>::Height(Node<elemType> *t)
//得到以t为根二叉树的高度，递归算法实现。
{
    int hl, hr;
    if (!t) return 0;
    hl = Height(t->left);
    hr = Height(t->right);
    if (hl>=hr) return 1+hl;    return 1+hr;
} // !不要忘了自己的高度！

template <class elemType>
void BTree<elemType>::DelTree()
{  DelTree(root);
    root = NULL;   }

template <class elemType>
void BTree<elemType>::DelTree(Node<elemType> *t) // 删除一个指针
//删除以t为根的二叉树，递归算法实现
{  if (!t) return;
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

template <class elemType>
void BTree<elemType>::PreOrder(Node<elemType> *t)
//前序遍历以t为根二叉树递归算法的实现。
{  if (!t) return;
    cout << t->data;
    PreOrder(t->left);
    PreOrder(t->right);
}

template <class elemType>
void BTree<elemType>::PreOrder()
//前序遍历的非递归算法实现
{
    if (!root) return;
    Node<elemType> *p;
    seqStack<Node<elemType> *> s;
    s.push(root);
    while (!s.isEmpty())
    {   p=s.top();
        s.pop();
        cout << p->data;
        if (p->right) s.push(p->right); // !顺序很重要！！先右后左
        if (p->left)  s.push(p->left);
    }
    cout << endl;
}

template <class elemType>
void BTree<elemType>::InOrder(Node<elemType> *t)
//中序遍历以t为根二叉树递归算法的实现。
{  if (!t) return;
    InOrder(t->left);
    cout << t->data;
    InOrder(t->right);
}

template <class elemType>
void BTree<elemType>::InOrder()
//中序遍历的非递归算法实现。
{  if (!root) return;
    seqStack<Node<elemType> *> s1;
    seqStack<int> s2; // * 记录栈
    Node<elemType> *p;
    int flag;
    int zero=0, one=1;
    p=root;
    s1.push(p); s2.push(zero);
    while (!s1.isEmpty())
    {   flag = s2.top();
        s2.pop();
        p = s1.top(); //读取栈顶元素
        if (flag==1)
        { 	s1.pop();
            cout << p->data;
            if (!p->right) continue;
            //有右子压右子，没有进入下一轮循环
            s1.push(p->right);
            s2.push(zero);
        }
        else
        {   s2.push(one);
            if (p->left) //有左子压左子
            {   s1.push(p->left);
                s2.push(zero);
            }
        }
    }
    cout<<endl;
}

template <class elemType>
void BTree<elemType>::PostOrder(Node<elemType> *t)
//后序遍历以t为根二叉树递归算法的实现。
{
    if (!t) return;
    PostOrder(t->left);
    PostOrder(t->right);
    cout << t->data;
}

template <class elemType>
void BTree<elemType>::PostOrder()
//后序遍历的非递归算法实现。
{  if (!root) return;
    Node<elemType> *p;
    seqStack<Node<elemType> *> s1;
    seqStack<int> s2;
    int zero=0, one=1, two=2;
    int flag;
    s1.push(root); s2.push(zero);
    while (!s1.isEmpty())
    {
        flag = s2.top(); s2.pop();
        p = s1.top();
        switch(flag)
        {   case 2:  s1.pop();
                cout << p->data;
                break;
            case 1:  s2.push(two);
                if (p->right)
                {
                    s1.push(p->right);
                    s2.push(zero);
                }
                break;
            case 0:    s2.push(one);
                if (p->left)
                {  s1.push(p->left);
                    s2.push(zero);
                }
                break;
        };//switch
    }//while
}

template <class elemType> // * 队列实现层次遍历
void BTree<elemType>::LevelOrder()
//层次遍历二叉树算法的实现。
{   seqQueue<Node<elemType> *> que;
    Node<elemType> *p;
    if (!root) return; //二叉树为空
    que.enQueue(root);
    while (!que.isEmpty())
    {
        p = que.front();
        que.deQueue();
        cout << p->data;
3
        if (p->left) que.enQueue(p->left);
        if (p->right)que.enQueue(p->right);
    }
    cout << endl;
}

#endif