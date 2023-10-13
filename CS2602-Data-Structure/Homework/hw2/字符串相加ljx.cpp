
#include<iostream>

using namespace std;
int i = 0;
char ans[601] ="";

char* add_two_string(char *p, char *q)
{

    bool flag = true;
    int tmp =  0;
    int carry = 0;
    while(true)
    {
        if(p[i] == '\0' )
        {
            flag = true;
            break;
        }
        if(q[i] == '\0')
        {
            flag = false;
            break;
        }

        tmp = (p[i] - '0') + (q[i] - '0') + carry ;
        carry = tmp / 10;
        tmp = tmp % 10;
        ans[i] = '0' + tmp;
        i ++;
    }

    if(flag)
    {
        while(q[i] != '\0')
        {
            tmp =  (q[i] - '0') + carry ;
            carry = tmp / 10;
            tmp = tmp % 10;
            ans[i] = '0' + tmp;
            i ++ ;
        }
    }
    else
    {
        while(p[i] != '\0')
        {
            tmp =  (p[i] - '0') + carry ;
            carry = tmp / 10;
            tmp = tmp % 10;
            ans[i] = '0' + tmp;
            i ++;
        }
    }

    if(carry == 1)
    {ans[i] = '1';
        i ++;
    }
    ans[i] = '\0';

    return ans;

}


int main()
{
    char str1[601] = "";
    char str2[601] = "";

    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> str1[i];
    }
    str1[n - 1] = '\0';

    for(int i = 0; i < m - 1; i ++)
    {
        cin >> str2[i];
    }
    str2[m - 1] = '\0';

    cout << add_two_string(str1,str2);


}
