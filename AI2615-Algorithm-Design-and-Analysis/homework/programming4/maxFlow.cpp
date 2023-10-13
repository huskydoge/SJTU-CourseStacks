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

const int N = 210;
vector<edge> G[N];
bool exist[N][N];
bool unuseful[N];

void add_edge (int u, int v, int flow) {
    int uid = (int) G[u].size(), vid = (int) G[v].size();
    G[u].push_back({v, flow, vid});
    G[v].push_back({u, 0, uid});
}

void merge_edge(int u,int v, int c){
    for (auto &[to, flow, rid] : G[u]) {
        if(to == v){
            flow += c;
            return;
        }
    }
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
                return used;
            }
        }
    }
    return 0;
}


// 输入可能有重边和自环
int main(){
    // n is the number of vertices, m is the number of edges
    int n, m;
    scanf("%d%d",&n,&m);
    bool hasPath = true;
    memset(unuseful, false, sizeof(unuseful));
    int k = 0;
    int u, v, c;
    for (int i = 0; i < m; ++ i){
        scanf("%d%d%d",&u,&v,&c);
        if(u == v || v == 1){
            continue; // 处理自环和回到源的边
        }
        if(exist[u][v]) {
            merge_edge(u, v, c); // 处理重边
        }
        else {
            exist[u][v] = true;
            add_edge(u,v,c);
        }


    }

    while(hasPath) {
        hasPath = false;
        memset(unuseful, false, sizeof(unuseful));
        if(dfs(1,210,n) > 0) {
            hasPath = true;
        }
        if(!hasPath){
            break;
        }
    }

    int res = 0;

    for (auto &[to, flow, rid]: G[1]){
        res += G[to][rid].flow;
    }
    cout << res;
}