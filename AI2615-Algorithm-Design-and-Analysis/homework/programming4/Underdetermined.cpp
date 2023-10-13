//
// Created by 黄奔皓 on 2023/5/24.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 105;
int n;
int A[MAXN][MAXN];
int match[MAXN];
bool visited[MAXN];

bool dfs(int u) {
    for (int v = 1; v <= n; ++v) {
        if (!visited[v] && A[u][v]) {
            visited[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            ans++;
        }
    }

    if (ans == n) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j == match[i]) {
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

    return 0;
}
