#include <iostream>
#include "baseSort.h"
using namespace std;

void print(int a[], int n){
    for(int i = 0; i < n; ++ i){
        cout << a[i] << endl;
    }
}
int main() {
    int a[4] = {712312, 1123, 81, 5};
    pocketSort(a, 4);
    print(a, 4);
    return 0;
}


