//
// Created by 黄奔皓 on 2022/10/28.
//

#ifndef TREE_HUFFMAN_H
#define TREE_HUFFMAN_H
#include "seqStack.h"

//存储Huffman结点
template <class elemType>
struct HuffmanNode
{
    elemType data;
    double weight;
    int parent;
    int left, right;
};


/* !时间复杂度分析：
为n个叶子结点设置初始状态，时间消耗O(n)。
执行了n-1次创建新的中间结点操作，每次创建要在所有元素(元素个数在n和2n之间)中两次去找权值最小的元素，时间耗费为2n。
算法总的时间复杂度为O(𝑛^2)。
*/

// !在所有父亲为0的元素中找最小值的下标,初始化都让父亲为0，BT[] = [0,1,2,3,4,.....,n-1, n, n + 1, .. ,2n - 1]
template <class elemType>
int minIndex(HuffmanNode<elemType> Bt[], int k, int m)
{   int i, min, minWeight = 9999;//用一个不可能且很大的权值
    for (i=m-1; i>k; i--)
    {
        if ((Bt[i].parent==0)&&(Bt[i].weight < minWeight))
        {
            min = i;
            minWeight = Bt[min].weight;
        }
    }
    return min;
}

template <class elemType>
HuffmanNode<elemType> *BestBinaryTree ( elemType a[], double w[], int n)
{
    HuffmanNode<elemType> *BBTree;
    int first_min, second_min; //
    int m=n*2; //共2n-1个结点，下标为0处不放结点
    int i, j;
    //!在数组中从后往前存储叶子结点,倒放
    BBTree = new HuffmanNode<elemType>[m];
    for (j=0; j<n; j++)
    {   i = m-1-j;
        BBTree[i].data = a[j];
        BBTree[i].weight = w[j];
        BBTree[i].parent = 0;
        BBTree[i].left = 0;
        BBTree[i].right = 0;
    }
    i = n-1; // i is the position which is ready for the first new node
    while (i!=0) //数组左侧尚有未用空间，即新创建的结点个数还不足
    {   first_min = minIndex(BBTree, i, m);  BBTree[first_min].parent = i;
        second_min = minIndex(BBTree, i, m);  BBTree[second_min].parent = i;
        BBTree[i].weight = BBTree[first_min].weight + BBTree[second_min].weight;
        BBTree[i].parent = 0;
        BBTree[i].left = first_min; BBTree[i].right = second_min;
        i--;  // !每次都要更新，新的权重加入到BBTree
    }
    return BBTree;
}

/*
 算法包含了两重循环，外循环次数为叶子结点的个数n，内循环串行地做了两件事：
 一个是从叶子逐步追溯到根获取哈夫曼编码的逆序，一个是逐步弹栈获取哈夫曼编码。
 内循环的两个操作消耗的时间都最多是哈夫曼树的高度，而哈夫曼树的形态、高度取决于这组字符的频度分布。
 最好时，哈夫曼可能达到的树高是log_2(𝑛)；最差时，哈夫曼树的树高会达到n，
 因此求哈夫曼编码算法的时间复杂度最好为O(nlog_2(𝑛))，最差为O(𝑛^2)。

 */
template <class elemType>
char ** HuffmanCode ( HuffmanNode<elemType> BBTree[ ], int n )
//n为待编码元素的个数，BBTree数组为Huffman树，数组长度为2n
{
    seqStack<char> s;
    char **HFCode;
    char zero = '0', one = '1';
    int m, i, j, parent, child;
    //为HFCode创建空间
    HFCode = new char* [n];
    for (i=0; i<n; i++)
        HFCode[i] = new char[n+1]; //每位元素编码最长n-1位，+1为n=1时储备

    m=2*n; //BBTree数组长度
    if (n==0) return HFCode; //没有元素
    if (n==1) //元素个数为1
    {
        HFCode[0][0] = '0', HFCode[0][1] = '\0';
        return HFCode;
    }
    for (i=m-1; i>=n; i--)
    {
        child=i;
        parent = BBTree[child].parent;
        while (parent!=0)
        {
            if (BBTree[parent].left==child)
                s.push(zero);
            else
                s.push(one);
            child = parent;
            parent = BBTree[parent].parent;
        }
        j=0;
        while (!s.isEmpty())
        {
            HFCode[m-i-1][j] = s.top();
            s.pop();
            j++;
        }
        HFCode[m-i-1][j] = '\0';
    }
    return HFCode;
}


#endif //TREE_HUFFMAN_H
