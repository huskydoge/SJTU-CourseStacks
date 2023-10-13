//
// Created by 黄奔皓 on 2022/12/12.
// https://acm.sjtu.edu.cn/OnlineJudge/problem?problem_id=13002

#include "iostream"
using namespace std;

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
void mergeSort(elemType a[], int n)
{
    mergeSort(a, 0, n-1);
}



int main(){
    int numberMap[1001];
    for(int i = 0; i < 1001; i ++){
        numberMap[i] = 0;
    }

    int numbers[101]; // 储存去重后的数
    int n = 0; // 数组长度
    cin >> n;
    int tmp = -1;
    int cnt = 0;
    int k = 0; // 储存处理好的数据的数组的下标

    for(int i = 0; i < n; ++ i){
        cin >> tmp;
        if(numberMap[tmp] == 0){
            numberMap[tmp] = 1;
            numbers[k] = tmp;
            ++ cnt;
            ++ k;
        }
    }

    mergeSort(numbers, cnt);

    cout << cnt << endl;
    cout << endl;

    for(int j = 0; j < cnt; ++j){
        cout << numbers[j] << ' ';
    }

    cout << endl;







}
