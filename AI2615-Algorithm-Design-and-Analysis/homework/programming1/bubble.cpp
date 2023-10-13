//
// Created by 黄奔皓 on 2023/2/24.
//

#include "iostream"
#include "cmath"
using namespace std;
const int N = 10e6 + 1;
int num[N];
int store[N];
int index_List[N];
void merge_sort(int *array, int l, int r){
    int *a = array;
    if(r - l <= 1){
        return;
    }

    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    int *tmp = new int[r - l];

    for(int i = 0; i < r - l; ++ i){
        index_List[a[l + i]] = l + i;
    }
    int i = l;
    int j = m;
    int k = 0;
    while(i < m && j < r){
        if(a[i] < a[j]){
            tmp[k ++] = a[i];
            i ++;
        } else {
            tmp[k ++] = a[j];
            j ++;
        }
    }

        while(i < m){
            tmp[k ++] = a[i];
            i ++;
        }
        while(j < r) {
            tmp[k++] = a[j];
            j++;
        }

    for(int _ = l; _ < k + l; ++ _){
        a[_] = tmp[_ - l];
        store[a[_]] += abs((index_List[a[_]] - _));
    }
    delete []tmp;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i){
        cin >> num[i];
        store[i] = 0;
    }
    merge_sort(num, 0, n);
    for(int i = 0; i < n; ++ i){
        cout << store[num[i]] << " ";
    }
}