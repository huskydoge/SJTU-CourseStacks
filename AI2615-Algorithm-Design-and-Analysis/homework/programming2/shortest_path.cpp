//
// Created by 黄奔皓 on 2023/3/21.
// 二叉堆参考 https://huskydoge.github.io/posts/大根堆和小根堆/，这是我上学期程序设计课的代码片段
#include "vector"
#include "iostream"
#include <cstring>
using namespace std;

struct edge {
    int v, w;
};
struct v_and_dist {
    int v;
    long long dist;
};

vector <edge> g[3000]; // g[i][j]
v_and_dist h[3000]; // heap
int num = 0;

void push(int x, int dist){
    h[++num] = {x, dist};
    int now = num, nxt = num >> 1; // nxt is father node
    while(nxt){
        if(h[now].dist >= h[nxt].dist) break;
        swap(h[now], h[nxt]);
        now = nxt;
        nxt >>= 1;
    }
}

v_and_dist top(){
    return h[1];
}

void pop_min(){
    h[1] = h[num--];
    int now = 1, nxt = 2;
    while(nxt <= num){
        if(nxt < num && h[nxt].dist > h[nxt+1].dist) ++nxt;
        if(h[now].dist <= h[nxt].dist) break;
        swap(h[now], h[nxt]);
        now = nxt;
        nxt <<= 1;
    }
}

void add_edge (int u, int v, int w) {
    g[u].push_back({v, w});
}

int main(){
    int n, m, s, t; // vertex, edge, source, destination, n <= 2500, m <= 6200
    int u,v,w; // from u to v with weight w
    long long t_dist[2501];
    bool found[2501];
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
        add_edge(v, u, w); // Undirected Graph!
    }

    // initialize
    t_dist[s] = 0;
    push(s,0);

    while(num > 0){
        v_and_dist tp = top();
        pop_min();
        if(found[tp.v]){
            continue;
        }
        found[tp.v] = true;
        if(found[t]){
            break;
        }
        for (auto [ver, weight] : g[tp.v]) {
            if(t_dist[ver] > tp.dist + weight){
                t_dist[ver] = tp.dist + weight;
                push(ver, t_dist[ver]);
            }
        }
    }

    cout << t_dist[t];

}