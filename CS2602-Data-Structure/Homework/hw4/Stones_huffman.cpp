//
// Created by 黄奔皓 on 2022/11/4.
//

#include "iostream"
#include "limits.h"
using namespace std;

struct HuffmanNode
{
    long weight;
    long long parent;
    long long left, right;
};

long long minIndex(HuffmanNode Bt[], long long k, long long m)
{   long long i, min, minWeight = INT_MAX;//用一个不可能且很大的权值
    for (i=m-1; i>k; i--)
    {
        if ((Bt[i].parent==0)&&(Bt[i].weight < minWeight))
        {   min = i;
            minWeight = Bt[min].weight;
        }
    }
    return min;
}

long BestBinaryTree (long w[], long long n)
{
    long ans = 0;
    HuffmanNode *BBTree;
    long long first_min, second_min; //
    long long m=n*2; //共2n-1个结点，下标为0处不放结点
    long long i, j;
    //!在数组中从后往前存储叶子结点,倒放
    BBTree = new HuffmanNode[m];
    for (j=0; j<n; j++)
    {   i = m-1-j;
        BBTree[i].weight = w[j];
        BBTree[i].parent = 0;
        BBTree[i].left = 0;
        BBTree[i].right = 0;
    }
    i = n-1; // i is the position which is ready for the first new node
    while (i!=0) //数组左侧尚有未用空间，即新创建的结点个数还不足
    {   first_min = minIndex(BBTree, i, m);
        BBTree[first_min].parent = i;
        second_min = minIndex(BBTree, i, m);
        BBTree[second_min].parent = i;
        BBTree[i].weight = BBTree[first_min].weight + BBTree[second_min].weight;
        BBTree[i].parent = 0;
        BBTree[i].left = first_min; BBTree[i].right = second_min;
        ans += BBTree[i].weight;
        i--;  // !每次都要更新，新的权重加入到BBTree
    }
    return ans;
}


int main(){
    long n = 0;
    long w[10010];
    cin >> n;
    for(long i = 0; i < n; ++ i){
        cin >> w[i];
    }

    cout << BestBinaryTree(w, n);

}