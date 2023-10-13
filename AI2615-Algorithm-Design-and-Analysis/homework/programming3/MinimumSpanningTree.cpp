//
// Created by 黄奔皓 on 2023/4/29.
// 二叉堆参考 https://huskydoge.github.io/posts/大根堆和小根堆/，这是我上学期程序设计课的代码片段
#include "vector"
#include "iostream"
using namespace std;

struct edge {
    int v, w; // v: destination, w: weight
};
struct v_and_cost {
    int v;
    int cost;
};

vector<edge> g[6000]; // g[i][j]
v_and_cost h[200010]; // heap, at most number of edges!!!!!
int num = 0;
long ans = 0;

void push(int x, int cost){
    h[++num] = {x, cost};
    int now = num, nxt = num >> 1; // nxt is father node
    while(nxt){
        if(h[now].cost >= h[nxt].cost) break;
        swap(h[now], h[nxt]);
        now = nxt;
        nxt >>= 1;
    }
}

v_and_cost top(){
    return h[1];
}

void pop_min(){
    h[1] = h[num--];
    int now = 1, nxt = 2;
    while(nxt <= num){
        if(nxt < num && h[nxt].cost > h[nxt+1].cost) ++nxt;
        if(h[now].cost <= h[nxt].cost) break;
        swap(h[now], h[nxt]);
        now = nxt;
        nxt <<= 1;
    }
}

void add_edge (int u, int v, int w) {
    g[u].push_back({v, w});
}

int main(){
    int n, m; // vertex, edge, n <= 5000, m <= 2*10^5
    int u,v,w; // from u to v with weight w
    int t_cost[6000];
    bool found[6000];
    // input
    scanf("%d",&n);scanf("%d",&m);
    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d",&u,&v,&w);
        // 排除自环
        if(u == v){
            continue;
        }
        add_edge(u, v, w);
        add_edge(v, u, w); // Undirected Graph!
    }

    for(int j = 2; j <= n; ++j){
        t_cost[j] = 10001;
    }
    // initialize
    t_cost[1] = 0;
    push(1,0);

    while(num > 0){
        v_and_cost tp = top();
        pop_min();
        if(found[tp.v]){
            continue;
        }
        found[tp.v] = true;
        ans += tp.cost;

        for (auto [ver, weight] : g[tp.v]) {
            if(t_cost[ver] > weight){
                t_cost[ver] = weight;
                push(ver, t_cost[ver]);
            }
        }
    }

    cout << ans;


}

