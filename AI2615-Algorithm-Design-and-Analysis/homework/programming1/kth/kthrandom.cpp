//
// Created by 黄奔皓 on 2023/2/24.
//

#include <random>
#include "vector"
#include "iostream"
using namespace std;
int n, k;
vector <int> a;

void read_input_data_vector()
{
    int m;
    cin >> n >> k >> m; a.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    unsigned int z = a[m - 1];
    for (int i = m; i < n; i++)
    {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}

int const choosePivot(vector<int> a){
    std::mt19937 rng(std::random_device{}());
    int pivot_index = rng() % a.size();
    return a[pivot_index];
}

int solve(vector<int> a, int k){
    // baseline
    if(a.size()==1){
        return a[0];
    }
    int pivot = choosePivot(a);
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

int main(){
    read_input_data_vector();
    cout << solve(a, k);
}
