//
// Created by 黄奔皓 on 2023/3/22.
//
#include "vector"
#include "iostream"
using namespace std;

vector <int> g[100001]; // g[i][j]
vector <int> r[100001]; // g[i][j]
bool g_visited[100001];
bool r_visited[100001];
int topo[100001]; // topo order
int step = 0;
long long v_num = 0;
long long ans = 0;

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
    v_num ++;
    for(auto v: g[u]){
        if(!g_visited[v]){
            g_dfs(v);
        }
    }
}

int main(){
    int m, n, u, v;
    scanf("%d%d",&m,&n);
    for(int k = 0; k < m; ++ k){
        scanf("%d%d",&u, &v);
        if(u == v){
            continue; // 处理自环
        }
        add_g_edge(u, v);
        add_r_edge(v,u);
    }

    for(int i = 1; i <= n; ++ i ){
        if(!r_visited[i]){
            r_dfs(i);
        }
    }

    while(step > 0){
        if(!g_visited[topo[step]]){ // 取反图中finish time最大的，也就是g中tail里的
            g_dfs(topo[step]);
            ans += ((v_num - 1) * v_num) >> 1;
            v_num = 0;
        }
        step --;
    }

    cout << ans;
}