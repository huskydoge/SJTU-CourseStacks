#include <iostream>
#include <cstring>
using namespace std;
char pre[100],mid[100],ans[2000];
void dfs(int pre_start, int pre_end, int mid_start, int mid_end, int index, int& max)
{
    int root, l, r; // 找前序遍历首位（root）在中序遍历中的下标
    for (root = mid_start;root < mid_end;++root){
        if (mid[root]==pre[pre_start])
            break;
    }
    ans[index] = mid[root];
    if (index > max) max = index;
    l = root-mid_start;
    // 左右孩子和父亲i在层次遍历中满足的下标关系： 左孩子是 2i, 右孩子是 2i + 1
    if (l>0) dfs(pre_start+1,pre_start+l,mid_start,root,index * 2, max);
    r=mid_end-root-1;
    if (r>0) dfs(pre_start+l+1,pre_end,root+1,mid_end,index*2+1, max);
}
int main() {
    int max = 0; // 记载数组的大小
    cin >> pre;
    cin >> mid;
    dfs(0,strlen(pre),0,strlen(mid),1, max);
    for (int i=1;i <= max;++i) // 怎么做到判断空的？
        if (ans[i]) cout<<ans[i]<<" ";
        else cout<<"NULL ";
    return 0;
}