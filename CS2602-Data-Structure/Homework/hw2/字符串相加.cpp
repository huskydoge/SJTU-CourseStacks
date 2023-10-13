#include "iostream"
using namespace std;

int i = 0;
char ans[601]="";

char* add_two_string(char *p, char *q){
    int tmp, carry = 0;
    bool flag = true;

    while(true){
        if(p[i] == '\0'){
            flag = true;
            break;
        }
        if(q[i] == '\0'){
            flag = false;
            break;
        }

        tmp = (p[i] - '0') + ( q[i] - '0') + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        ans[i] = tmp + '0';
        ++ i;
    }

    if(flag){
        while(q[i] != '\0'){
            tmp = (q[i] - '0') + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            ans[i] = tmp + '0';
            ++ i;
        }
    }
    else{
        while(p[i] != '\0'){
            tmp = (p[i] - '0') + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            ans[i] = tmp + '0';
            ++ i;
        }
    }

    if(carry == 1){
        ans[i] = '1';
        ++ i;
    }

    ans[i] = '\0';
    return ans;


}

int main() {

    int m = 1, n = 1;

   cin >> m >> n;
   char str1[601];
   char str2[601];
//   cin >> str1 >> str2;
//
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> str1[i];
    }
    str1[n] = '\0';

    for(int i = 0; i < m - 1; i ++)
    {
        cin >> str2[i];
    }
    str2[m] = '\0';

   cout << add_two_string(str1, str2);
}