//
// Created by 黄奔皓 on 2022/11/5.
//

#ifndef FIND_STATICSEARCH_H
#define FIND_STATICSEARCH_H
class illegalSize{};
template <class elemType>
class staticSearch
{  private:
    elemType *data; // 存储静态数据
    int len;
public:
    staticSearch(elemType a[], int n);
    int Search(const elemType &x) const;// *顺序查找 时间复杂度O(n)
    int BSearch(const elemType &x) const;// *折半查找 O(log2(n))
    ~staticSearch(){delete []data;}
};
template <class elemType>
staticSearch<elemType>::staticSearch(elemType a[], int n)
{
    len = n;
    data = new elemType[n+1]; // 多一个哨兵位
    if (!data) throw illegalSize();
    for (int i=1; i<n+1; i++) data[i]=a[i-1]; // ?0下标不用
}

template <class elemType>
int staticSearch<elemType>::Search(const elemType &x) const //顺序查找
{
    int i;
    data[0] = x;
    for (i=len; i>=0; i--)  if (data[i]==x) break;
    return i;
}
template <class elemType>
int staticSearch<elemType>::BSearch(const elemType &x) const//折半查找
{
    int mid, low, high;
    low=1; high=len;
    while (low<=high)
    {  mid = (low+high)/2;
        if (x==data[mid]) break; //查找成功
        else
        if (x<data[mid]) high = mid -1;  //x小于中间位置元素
        else  low = mid +1;    //x大于中间位置元素
    }
    if (low<=high) return mid;
    return 0;
}



#endif //FIND_STATICSEARCH_H
