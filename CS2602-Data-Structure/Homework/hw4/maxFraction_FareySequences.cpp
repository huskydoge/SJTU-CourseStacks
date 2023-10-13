//
// Created by 黄奔皓 on 2022/11/6.
//
#include<cstdio>

void farey(int n, int ans)
{
    int k, a0 = 0, b0 = 1, a1 = 1, b1 = n, a2, b2;
    for (int i = 0; i < ans - 1; ++i) /// 由于第1项已算出(1/n)，所以算ans-1次就行
    {
        k = (n + b0) / b1;///k要尽量取大
        a2 = k * a1 - a0;
        b2 = k * b1 - b0;///利用前两项计算出下一项
        a0 = a1, a1 = a2;
        b0 = b1, b1 = b2;///移动
    }
    printf("%d/%d\n", b1 - a1, b1);
}

int main()
{
    int n, ans;
    scanf("%d%d", &n, &ans);
    farey(n, ans);
    return 0;
}