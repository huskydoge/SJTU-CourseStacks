//
// Created by 黄奔皓 on 2023/3/22.
//
//
// Created by 黄奔皓 on 2023/3/21.
// 二叉堆参考 https://huskydoge.github.io/posts/大根堆和小根堆/，这是我上学期程序设计课的代码片段
#include "vector"
#include "iostream"
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
struct edge {
    int v, w;
};

vector <edge> g[6250]; // g[i][j]

void add_edge (int u, int v, int w) {
    g[u].push_back({v, w});
}

int main(){
    int n, m, s, t; // vertex, edge, source, destination, n <= 2500, m <= 6200
    int u,v,w; // from u to v with weight w
    long long t_dist[2550];
    bool found[2550];
    bool store[2550];
    int min_i = 0;
    int num = 0;
    memset(t_dist, 0x3f, sizeof(t_dist));
    // input
    scanf("%d",&n);scanf("%d",&m);scanf("%d",&s);scanf("%d",&t);

    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d",&u,&v,&w);
        // 排除自环
        if(u == v){
            continue;
        }
        add_edge(u, v, w);
    }

    // initialize
    t_dist[s] = 0;
    store[s] = true;
    min_i = s;
    while(!found[t]){
        int min = INF;
        if(found[min_i]){
            for(int k = 1; k <= n; ++ k){
                if(store[k]){
                    if(min > t_dist[k]){
                        min = t_dist[k];
                        min_i = k;
                    }
                }
            }
            continue;
        }
        found[min_i] = true;
        store[min_i] = false;

        for (auto [ver, weight] : g[min_i]) {
            if(t_dist[ver] > t_dist[min_i] + weight){
                t_dist[ver] = t_dist[min_i] + weight;
                store[ver] = true;
            }
        }
        for(int k = 1; k <= n; ++ k){
            if(store[k]){
                if(min > t_dist[k]){
                    min = t_dist[k];
                    min_i = k;
                }
            }
        }
    }

    cout << t_dist[t];

}