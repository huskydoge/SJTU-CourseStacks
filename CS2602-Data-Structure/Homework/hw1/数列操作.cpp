//
// Created by 黄奔皓 on 2022/9/26.
//
#include<iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }

    long positive = 0;
    long minus = 0;
    long temp = 0;

    long a[n],b[n],d[n];

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    for(int i = 0; i < n; ++i){
        d[i] = a[i] - b[i];
    }

    for(int i = 1; i < n; ++i){
        temp = d[i] - d[i - 1];
        if(temp > 0){
            positive += temp;
        } else {
            minus += -(temp);
        }
    }
    if(d[0] > 0){
        positive += d[0];
    } else {
        minus += -(d[0]);
    }

    cout << max(positive,minus) << endl;

}