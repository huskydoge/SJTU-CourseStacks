//
// Created by 黄奔皓 on 2022/11/27.
//

#include "iostream"
#include "string.h"
#include "algorithm"
using namespace std;
typedef unsigned long long ull;
ull base=131;
struct hashCode
{
    ull x,y;
};
hashCode arr[10010];
char s[10010];
int n,ans=1;
ull mod1=19260817;
ull mod2=19660813;
ull hash1(char s[])
{
    int len=strlen(s);
    ull res=0;
    for (int i=0;i<len;i++)
        res=(res * base+(ull)s[i])%mod1;
    return res;
}
ull hash2(char s[])
{
    int len=strlen(s);
    ull res=0;
    for (int i=0;i<len;i++)
        res=(res*base+(ull)s[i])%mod2;
    return res;
}
bool comp(hashCode a,hashCode b)
{
    return a.x<b.x;
}
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> s;
        arr[i].x=hash1(s);
        arr[i].y=hash2(s);
    }
    sort(arr+1,arr+n+1,comp);
    for (int i=2;i<=n;i++)
        if (arr[i].x!=arr[i-1].x || arr[i-1].y!=arr[i].y)
            ans++;
    cout << ans;
}
