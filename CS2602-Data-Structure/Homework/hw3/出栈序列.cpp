//
// Created by 黄奔皓 on 2022/10/14.
//

#include "iostream"
using namespace std;

inline void ans(bool flag){

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main(){
    int T = 0;
    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    bool flag;
    long a[1000010]; // （0 base）
    long c = 1; // 用来记录 凡是小于 c的数都已经逆序，即不需要检查c之后的数了
    long tmp = 0;
    cin >> T;
    long n = 0;
    while(T > 0){
        flag = true;
        cin >> n;

        for(long i = 0; i < n; ++ i){
            cin >> a[i]; // write in numbers
        }

       for(long i = 0; i < n; ++ i){
           if(a[i] <= c) continue; // 在i的右侧，小于c的都已经是逆序了

           tmp = a[i];
           for (long j = i + 1; j < n; ++ j){
               if(a[j] < a[i]){
                   if(a[j] > tmp){
                       flag = false;
                       break;
                   } else {
                       tmp = a[j];
                   }
               }
           }
           if(!flag) break;
           else c = a[i];
       }

       c = 1;
        ans(flag);
        -- T;
}
}