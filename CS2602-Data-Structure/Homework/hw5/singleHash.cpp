//
// Created by 黄奔皓 on 2022/11/27.
//
// scanf比cin要快很多！！！
#define _CRT_SECURE_NO_WARNINGS //关闭安全检查
#include "string.h"
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
ull base = 131;
ull a[10010];
char s[10010];
int n, ans = 1;
ull mod = 212370440130137957ll; // long long类型，在赋初值的时候，如果大于2的31次方-1，那么后面需要加上LL
ull hashCode(char p[])
{
    int len = strlen(p);
    ull res = 0;
    for (int i = 0; i < len; i++)
        res = (res * base + (ull)s[i]); //自然溢出，如果用单哈希则主动 mod
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        a[i] = hashCode(s);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i + 1])
            ans++;
    }
    printf("%d", ans);
}

