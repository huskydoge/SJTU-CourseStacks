//
// Created by 黄奔皓 on 2023/2/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k;
vector <LL> a;

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

LL const getSubsetMedian(vector<LL> a, LL l, LL r){
    // 大小为5的集合
    sort(a.begin() + l, a.begin() + r + 1);
    return a[l + r / 2];
}

LL solve(vector<LL> a, LL k);

LL const choosePivot(vector<LL> a){
    vector<LL> m;
    LL i = 0;
    for(; i < a.size() / 5; ++ i){
        m.push_back(getSubsetMedian(a, 5 * i,5 * (i + 1) ));
    }
    if(a.size() > 5 * i){
        m.push_back(getSubsetMedian(a, 5 * i,a.size() - 1));
    }
    return (solve(m, m.size() / 2));
}

LL solve(vector<LL> a, LL k){
    // baseline
    if(a.size()==1){
        return a[0];
    }
    LL pivot = choosePivot(a);
    vector<LL> L;
    vector<LL> M;
    vector<LL> R;

    // O(n)
    for(LL j = 0; j < a.size(); ++j){
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