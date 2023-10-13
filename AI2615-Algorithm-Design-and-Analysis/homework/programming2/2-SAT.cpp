//
// Created by 黄奔皓 on 2023/3/22.
//
#include "vector"
#include "iostream"
#include "cstring"
using namespace std;

vector <int> g[2000010]; // g[i][j]
vector <int> r[2000010]; // g[i][j]
bool g_visited[2000010];
bool r_visited[2000010];
int topo[2000010];
//int mark[1000010];
int ans[1000010];
bool ensured[1000010];
int c[1000010];
int cnt = 0;
int step = 0;
bool flag = true;

void add_g_edge(int u, int v) {
    g[u].push_back(v);
}

void add_r_edge(int u, int v) {
    r[u].push_back(v);
}

void r_dfs(int u){
    r_visited[u] = true;
    for(auto v: r[u]){
        if(!r_visited[v]){
            r_dfs(v);
        }
    }
    step ++;
    topo[step] = u;
}

void g_dfs(int u){
    g_visited[u] = true;
    if(c[u / 2] == cnt){
        flag = false;
        return;
    }
    c[u / 2] = cnt;
    if(!ensured[u / 2]){ // 如果这个点还没被确定，就把它确定。我们是从正图的tail SCC开始的，确定过的值就一定
        ensured[u / 2] = true;
        ans[u / 2] = u % 2;
    }

    for(auto v: g[u]){
        if(!g_visited[v]){
            g_dfs(v);
            if(!flag){
                return; // 避免不必要的检查
            }
        }
    }
}

int main(){
    int m, n, i_, j_, a, b;
    memset(c, 0, sizeof(c));
    scanf("%d%d",&n,&m); // n variables, m constraints
    for(int k = 0; k < m; ++ k){
        scanf("%d%d%d%d",&i_, &a, &j_, &b);
        i_ --; j_ --;
//        mark[i_] = true;
//        mark[j_] = true;
        add_g_edge(2 * i_ + !a, 2 * j_ + b);
        add_g_edge(2 * j_ + !b, 2 * i_ + a);
        add_r_edge(2 * j_ + b, 2 * i_ + !a);
        add_r_edge(2 * i_ + a, 2 * j_ + !b);
    }

    for(int i = 0; i < 2 * n; ++ i ){
//        if(mark[i / 2]){
            if(!r_visited[i]){
                r_dfs(i);
            }
//        }
    }

    while(step > 0){
        if(!g_visited[topo[step]]){
            cnt ++; // 进入一个SCC
            g_dfs(topo[step]);
        }
        step --;
    }

    if(flag){
        cout << "Yes\n";
        for(int i = 0; i < n; ++ i){
            cout << ans[i] << " ";
        }
    } else {
        cout << "No";
    }
}