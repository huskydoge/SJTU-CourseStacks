//
// Created by 黄奔皓 on 2023/2/24.
//
#include "iostream"
#include <algorithm>
using namespace std;

const int N = 4e7 + 1;
int n, k;
int a[N];

int solve(int* a, int left, int right, int k);


int choosePivot(int* a, int left, int right);


int partition(int *a, int left, int right, int pivot_index, int k);


int getSubsetMedian(int L[], int left, int right);

int choosePivot(int *a, int left, int right) {
    if (right - left < 5) {
        return getSubsetMedian(a, left, right);
    }
    int m[N];
    for (int i = left; i <= right; i += 5) {
        int sub_right = min(i + 4, right);
        int median5 = getSubsetMedian(a, i, sub_right);
        m[i / 5] = median5;
    }
    return
}

int solve(int* a, int left, int right, int k) {
    int pivot = 0;
    if(right == 1){
        return a[0];
    } else if(a.size() <= 5){
        sort(a.begin(), a.end());
        return a[k - 1];
    } else {
        pivot = choosePivot(a);
    }
    vector<int> L;
    vector<int> M;
    vector<int> R;

    // O(n)
    for(int j = 0; j < a.size(); ++j){
        if(a[j] < pivot){
            L.push_back(a[j]);
        } else if(a[j] == pivot){
            M.push_back(a[j]);
        } else {
            R.push_back(a[j]);
        }
    }

    if(k <= L.size()){
        return solve(L, k);
    } else if(k <= L.size() + M.size()){
        return M[0]; // base line
    } else {
        return solve(R, k - L.size() - M.size());
    }
}

int partition(int L[], int left, int right, int pivot_index, int k) {
    int pivot_value = L[pivot_index];
    swap(L[pivot_index], L[right]);
    // ---[=]=[=]+++
    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (L[i] < pivot_value) {
            swap(L[store_index++], L[i]);
        }
    }
    int store_index_eq = store_index;
    for (int i = store_index; i < right; ++i) {
        if (L[i] == pivot_value) {
            swap(L[store_index_eq++], L[i]);
        }
    }
    swap(L[right], L[store_index_eq]);
    if (k < store_index)
        return store_index;
    else if (k < store_index_eq)
        return k;
    else
        return store_index_eq;
}

int partition5(int L[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int j = i;
        while (j > left && L[j - 1] > L[j]) {
            swap(L[j - 1], L[j]);
            --j;
        }
    }
    return (left + right) / 2;  // return middle index (the median index)
}

void read_input_data_array() {
    int m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    a = new int[n];
    L = new int[n];
    M = new int[n];
    R = new int[n];
    unsigned int z = a[m];
    for (int i = m + 1; i <= n; i++) {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}



int main(){
    read_input_data_array();
    cout << solve(a, k);

}