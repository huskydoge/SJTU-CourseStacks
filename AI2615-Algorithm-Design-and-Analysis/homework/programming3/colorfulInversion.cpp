//
// Created by 黄奔皓 on 2023/4/29.
//

#include "iostream"
using namespace std;

int n;
int r, l, mid;
int a[100010];
int d[100010]; // d[i] is the length of decreasing sequence ended by a[i]
int e[100010]; // e[i] is the maximal number which is the end of a decreasing sequence of length i + 1

int main(){

    scanf("%d",&n);

    int len = 0; // the length of e[]

    for(int i=0; i < n; ++ i){
        scanf("%d",&a[i]);
        e[i] = 1e6 + 1;
    }

    for(int i = 0;i < n; ++ i){
        r = len;
        l = 0;
        while(l < r){
            mid = (l+r) / 2;
            if(e[mid] > a[i]){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        len = max(len, r + 1);
        e[r] = a[i];
        d[i] = r + 1;
    }

    for(int i=0; i < n; ++ i){
        cout << d[i] << ' ';
    }

}