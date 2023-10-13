//
// Created by 黄奔皓 on 2023/4/29.
//

#include "iostream"
using namespace std;

int n,m; // n days, m works
int si, ti, ai;
int t[370]; // most valuable work at day i, and the work will occupy day i to t[i]
int e[370]; // earnings after day[i]
long long x;

// e[i] = max{1 + e[t[i] + 1], e[i+1]}
int min(int a, int b){
    return a <= b ? a: b;
}

int max(int a, int b){
    return a >= b ? a: b;
}

int main(){
    for(int i = 0; i < 371; ++ i){
        t[i] = 366;
        e[i] = 0;
    }
    scanf("%d",&n);scanf("%d",&m);scanf("%d",&x);
    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d",&si,&ti,&ai);
        t[si] = min(ti, t[si]);
    }
    if(t[n] == n){
        e[n] = 1;
    } else {
        e[n] = 0;
    }

    for(int k = n - 1; k >= 1; -- k ){
        if(t[k] > n){
            e[k] = e[k + 1];
        } else {
            e[k] = max(1 + e[t[k] + 1], e[k + 1]);
        }
    }

    cout << e[1];

}