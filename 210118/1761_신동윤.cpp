/*
    BOJ 1761 정점들의 거리
    https://www.acmicpc.net/problem/1761
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX_N 40001
#define MAX 17  // 반올림 log(2, 40000)

using namespace std;

int n, m;
int dist[MAX_N];                    // 루트노드로 부터의 거리
int parent[MAX_N][MAX];             // parent[i][k] : i의 2^k 번째 부모
int depth[MAX_N];                   // 트리에서의 깊이
vector<pair<int, int>> adj[MAX_N];  // adj[i].first = i 와 연결된 노드 번호가 first, adj[i].second = i 와 first 간 거리

void make_tree(int cur, int distance) {  // 현재 노드, 루트 ~ 현재노드 까지의 거리
    for (int i = 0; i < adj[cur].size(); ++i) {
        int next = adj[cur][i].first;
        int temp = distance;
        if (depth[next] == -1) {
            temp += adj[cur][i].second;
            dist[next] += temp;
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            make_tree(next, temp);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, distance;
        cin >> u >> v >> distance;
        u--;
        v--;  // 편의상 인덱스 맞추기위해 감소 시켜서 넣음
        adj[u].push_back({v, distance});
        adj[v].push_back({u, distance});
    }

    memset(parent, -1, sizeof(parent));
    fill(depth, depth + n, -1);
    depth[0] = 0;
    make_tree(0, 0);

    for (int j = 0; j < MAX - 1; ++j)
        for (int i = 1; i < n; ++i)
            if (parent[i][j] != -1)
                parent[i][j + 1] = parent[parent[i][j]][j];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, temp_u, temp_v;
        cin >> u >> v;
        u--;
        v--;

        temp_u = u;
        temp_v = v;

        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; diff; ++j) {
            if (diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if (u != v) {
            for (int j = MAX - 1; j >= 0; --j) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }

        cout << dist[temp_u] + dist[temp_v] - (2 * dist[u]) << "\n";
    }

    return 0;
}