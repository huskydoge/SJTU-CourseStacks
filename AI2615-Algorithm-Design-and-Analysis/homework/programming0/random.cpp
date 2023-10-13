//
// Created by 黄奔皓 on 2023/2/14.
// 参考了网站：https://blog.csdn.net/pspdragon/article/details/78268055
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1295
#include <stdio.h>

long numOfPrime(long n){
    if(n == 1){
        return 0;
    }

    // 1-index
    bool* isPrime = new bool [n + 1];
    for(long i = 2; i <= n; ++ i){
        isPrime[i] = 1;
    }

    long j = 2;
    for(long k = 2; k <= n; ++ k){
        if(!isPrime[k]){
            continue;
        } else {
            while(j * k <= n){
                isPrime[j * k] = 0;
                ++ j;
            }
            j = 2;
        }
    }

    long ans = 0;
    for(long i = 2; i <= n; ++ i ){
        if(isPrime[i]){
            ++ ans;
        }
    }
    delete []isPrime;
    return ans;
}


int main() {
    long n;
    scanf("%ld", &n);
    if(n >= 100000){
        printf("%.6lf",0.000000);
    } else {
        printf("%.6lf", 2.0 * numOfPrime(n) / n / n);
    }
}

