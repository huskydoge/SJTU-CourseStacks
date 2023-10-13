
#include <iostream>
using namespace std;

int tree[10010];
int m;

// 树状数组
inline int lowbit(int x) {
    return x & (-x);
}

void update(int ind,int val) {
    for(int i = ind; i <= m; i += lowbit(i))
        tree[i] += val;
}

int sum(int index) { // 查询 1 - index 数列元素的和
    int res = 0;
    for(int i = index; i > 0; i -= lowbit(i))
        res += tree[i];
    return res;
}

void search(int &l, int &r, int k) { //二分查找, 找到数组中第一个满足元素和为k的 下标
    while(l < r) {
        int mid = (l + r) >> 1;
        if(sum(mid) < k)
            l = mid + 1;
        else r = mid;
    }
}

int main() {
    ios::sync_with_stdio(false);//可关闭和stdio同步加速
    int curNum,index,l,r;
    cin >> m;
    index = 1;curNum = m; // 下标，当前剩下的猴子数量, 1 base

    for(int i = 1; i <= m; ++i)
        update(i,1);  // 数组中为 1 代表存活，为 0 代表淘汰

    int i = 0;
    while(i < m){
        int k;
        if(i < m - 1) cin >> k;
        else k = 1;

        index += (k - 1); // index 更新

        index = (index - 1) % curNum + 1; //计算在新的队列 (cur长度改变) 中位于第几个 (% curNum 消除周期性)

        l = 1,r = m;
        search(l, r, index);

        curNum--;
        update(r,-1);  // 把下标为r处的元素值设置为 1 + -1 = 0， 代表第r只猴子淘汰
        ++ i;
    }

    cout << l << endl;

    return 0;
}