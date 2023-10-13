//
// Created by 黄奔皓 on 2022/12/11.
// https://acm.sjtu.edu.cn/OnlineJudge/problem?problem_id=1173
#include "iostream"
using namespace std;

template <class elemType>
void merge(elemType a[], long low, long mid, long high)
{
    long i, j, k;
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
void mergeSort(elemType a[],long low, long high)
{
    long mid;
    if (low>=high) return;
    mid =(low+high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

template <class elemType>
void mergeSort(elemType a[], long n)
{
    mergeSort(a, 0, n-1);
}


int main(){
    long len = 0;
    cin >> len;
    long a[100001];
    long b[100001];
    for(long j = 0; j < len; ++ j){
        cin >> a[j];
    }
    for(long j = 0; j < len; ++ j){
        cin >> b[j];
    }

    mergeSort(a, len);
    mergeSort(b, len);

    long max = 0;
    long min = 0;

    for(long k = 0; k < len; ++ k){
        max += a[k] * b[k];
        min += a[k] * b[len - 1 - k];
    }

    cout << max << ' ' << min << endl;

}

