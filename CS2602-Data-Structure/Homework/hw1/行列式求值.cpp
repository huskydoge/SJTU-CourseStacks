//
// Created by 黄奔皓 on 2022/9/26.
//
#include <iostream>
#include <cmath>
using namespace std;

// 求逆序数
int Reverse(int n, int a[])
{
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        for (int h = 0; h < i; h++)
        {
            if (a[i]<a[h])
            {
                r =r + 1;
            }
        }
    }
    return r;
}

int cofactorDet(int arr[10][10], int a[], int n, int r)
{
    int det = 0;
    int temp = 1;
    int r_ = 0;

    for (int i = 0; i < n; i++)
    {
        temp = temp * arr[i][a[i]-1];
    }

    r_ = pow(-1, r);

    det = temp * r_;

    return det;
}

void Perm(int start, int end, int a[], int arr[10][10], int &matrix_det)
{

    if (start == end)
    {
        matrix_det = matrix_det + cofactorDet(arr, a, end, Reverse(end, a));
        return;
    }
    for (int i = start; i < end; i++)
    {
        swap(a[start], a[i]);
        Perm(start + 1, end, a, arr, matrix_det);
        swap(a[i], a[start]);
    }

}


int main()
{
    int matrix_det = 0;
    int i, n, a[10];
    int arr[10][10];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int h = 0; h < n; h++)
        {
            cin >> arr[i][h];
        }
    }

    Perm(0, n, a, arr, matrix_det);

    cout << matrix_det << endl;

    return 0;
}
