//
// Created by 黄奔皓 on 2023/5/24.
//

#include<cstring>
#include "vector"
#include "iostream"
using namespace std;

struct edge {
    int to, flow, rid;
};

const int N = 105; // n的范围
vector<edge> G[2 * N];
int A[N][N];
bool unuseful[2 * N];
int match[N];

void add_edge (int u, int v, int flow) {
    int uid = (int) G[u].size(), vid = (int) G[v].size();
    G[u].push_back({v, flow, vid});
    G[v].push_back({u, 0, uid});
}


int dfs(int u, int flow, int t){
    if (u == t) {
        return flow;
    }
    for (auto &[to, f, rid] : G[u]) {
        if(f > 0 && !unuseful[to]){
            unuseful[to] = true;
            int used = dfs(to, min(flow,f),t);
            if (used > 0) {
                f -= used;
                G[to][rid].flow += used;
                match[u] = to;
                return used;
            }
        }
    }
    return 0;
}


int main(){
    // n is the number of vertices
    int n;
    cin >> n;

    // Special Cases
    if(n==1){
        int x;
        cin >> x;
        if(!x){
            cout << "No";
        } else {
            cout << "Yes" << endl;
            cout << "1";
        }
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        add_edge(0,i,1);
        add_edge(n + i,2*n+1,1);
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
            // 若矩阵ij为1，则意味着左边第i个点和右边第j个点有一条边，我们的任务就是最大匹配，让它达到n
            if(A[i][j]){
                add_edge(i,n + j,1);
            }
        }
    }


    bool hasPath = true;
    // dfs实现最大流算法，见提示
    while(hasPath) {
        hasPath = false;
        memset(unuseful, false, sizeof(unuseful));
        if(dfs(0,210,2 * n + 1) > 0) {
            hasPath = true;
        }
        if(!hasPath){
            break;
        }
    }

    int res = 0;

    // 检查最大流
    for (auto &[to, flow, rid]: G[0]){
        res += G[to][rid].flow;
    }
    if(res == n){
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (n + j == match[i]) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }

}