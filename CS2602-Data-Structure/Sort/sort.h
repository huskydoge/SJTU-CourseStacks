//
// Created by 黄奔皓 on 2022/11/23.
//

#ifndef 排序算法_SORT_H
#define 排序算法_SORT_H

//最差时，每趟都有交换，复杂度：O(n2)。
//最好时，第一趟就没有交换，原本有序，复杂度：复杂度：O(n)。总体介于两者之间，一般称其复杂度为O(n2)
template <class elemType>
void bubbleSort(elemType a[], int n)
{
    int i, j;
    bool  change = true;
    elemType tmp;
    for (j=n-1; j>0 && change; j--)
    {
        change = false;
        for (i=0; i<j; i++)
            if (a[i]>a[i+1]) // 大于才换，等于不换，稳定！
            {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                change = true;
            } //if
    }
}

template <class elemType>
void insert(elemType a[], int n, const elemType &x)
//n为有序表a中当前元素的个数，x为待插入新元素
{
    int i;
    //从后往前找第一个不比x大的元素，大者后移一位
    for (i=n-1; i>=0; i--)
        if (a[i]<=x) break;
        else a[i+1] = a[i];

    a[i+1] = x; //在腾出的位置上存新元素x
}

template <class elemType>
void insertSort(elemType a[], int n)
{   int i;
    elemType tmp;
    //将第i个元素插入到前i-1个元素的有序序列中
    for (i=1; i<n; i++)
    {
        tmp = a[i];
        insert(a, i, tmp);
    }
}

template <class elemType>
void shellSort(elemType a[], int n)
{
    int step, i, j;
    elemType tmp;
    for (step=n/2; step>0; step/=2)
        for (i=step; i<n; i++)
        {
            tmp = a[i];
            j = i;
            while ((j-step>=0) && (tmp<=a[j-step]))
            {
                a[j] = a[j-step];
                j-=step;
            }
            a[j] = tmp;
        }
}

template <class elemType>
void merge(elemType a[], int low, int mid, int high)
{
    int i, j, k;
    elemType *c;
    //创建实际空间存储合并后结果
    c = new elemType[high-low+1]; // !如果申请静态数组的话，规模不能有变量！所以不要写 elemType c[high - low + 1];
    i = low;
    j = mid+1; //数组分割处
    k = 0;
    //两个有序序列中元素的比较合并
    while ((i<=mid)&&(j<=high))
    {
        if (a[i]<=a[j])
        {
            c[k]=a[i];
            i=i+1;
        } else {
            c[k]=a[j];
            j=j+1;
        }
        k=k+1;
    }
    //若a序列中i未越界，抄写剩余元素
    while (i<=mid)
    {
        c[k]=a[i];
        i=i+1;
        k=k+1;
    }
    //若b序列中j未越界，抄写剩余元素
    while (j<=high)
    {
        c[k]=a[j];
        j=j+1;
        k=k+1;
    }
    for (i=0;i<high-low+1; i++)   a[i+low] = c[i];
    delete []c;
}

template <class elemType>
void mergeSort(elemType a[], int n)
{
    mergeSort(a, 0, n-1);
}

template <class elemType>
void mergeSort(elemType a[],int low, int high)
{
    int mid;
    if (low>=high) return;
    mid =(low+high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

template <class elemType>
void quickSort(elemType a[], int n)
{
    quickSort(a, 0, n-1);
}

template <class elemType>
void quickSort(elemType a[], int start, int end)
{
    int i, j, hole;
    elemType temp;
//序列中没有元素或只有一个元素，递归结束
    if (end<=start) return;
    temp = a[start];
    hole = start;
    i=start; //从左到右搜索的指针
    j=end;   //从右到左搜索的指针

    while (i<j)
    {
        //从j位置开始从后往前找第一个小于temp的值
        while ((j>i)&&(a[j]>=temp)) j--;
        if (j==i) break;
        a[hole]=a[j];
        hole = j;
        //从i位置开始从前往后找第一个大于等于temp的值
        while ((i<j)&&(a[i]<temp)) i++;
        if (j==i) break;
        a[hole]=a[i];
        hole = i;
    }
    a[hole] = temp;
    //对标杆位置左边的序列实施同样的方法
    quickSort(a,start, hole-1);
    //对标杆位置右边的序列实施同样的方法
    quickSort(a,hole+1, end);
}

template <class elemType>
void selectSort(elemType a[], int n)
{
    int i, j,minIndex;
    elemType temp;
    for (i=0; i<n; i++)
    {   //为第i个位置找合适的数据
        minIndex = i;
        for (j=i+1; j<n; j++)
            if (a[j]<a[minIndex])   minIndex = j;
        //将minIndex位置上的数据
        //和位置i上数据交换
        if (minIndex == i) continue; // i 位置的元素就是最小值
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

//   一个完全二叉树中，任意一个结点的值比其左右子结点值都大，
//   称为大顶堆。
// 一个完全二叉树中，任意一个结点的值比其左右子结点值都小，
//   称为小顶堆。
//堆排序时间消耗由两部分组成：
//        初次建堆的时间消耗和摘取大顶的时间消耗。
//
//前者从形式上看时间复杂度是O(nlog_2𝑛),但实际可达O(n)；
//后者从形式上看时间复杂度也是O(nlog_2𝑛),但实际也可达O(n)；
template <class elemType>
void heapSort(elemType a[], int n)
{
    int i, j;
    elemType temp;
    //从倒数第一个非叶子结点开始调整，
    //首次建立大顶堆
    for (i= n / 2 - 1; i>=0; i--)
        adjust(a, n, i);

    // 建立大顶堆后，把堆顶元素（最大）和最后一个元素交换位置，重复过程，得到递增的中序遍历序列
    //换大顶，逐次减少参与的元素，每次都让最后一个元素不参与下次排序
    for (j=n-1; j>=1; j--)
    {
        //大顶和第i个位置元素交换
        temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        //调整第0个元素
        //重新调整为大顶堆
        adjust(a, j, 0);
    }
}

template <class elemType>
void adjust(elemType a[], int n, int i)
//对尺寸为n的数组a，假设根为0下标元素，调整下标为i的元素，使
//得以i为根的二叉树为一个大顶堆。
{
    int maxChild;
    elemType temp;
    while (true)
    {
        maxChild = 2*i+1;  //i的左子下标
        if (maxChild>n-1) return;
        if (maxChild+1<=n-1) //i还有右子
            if (a[maxChild+1]>= a[maxChild])
                maxChild++; //右子最大
        if (a[i]>a[maxChild]) return;
        // !孩子节点都已经是大顶堆了
        temp = a[i];
        a[i] = a[maxChild];
        a[maxChild] = temp;
        i = maxChild;  //继续向下调整
    }
}


#endif //排序算法_SORT_H
