/*
    BOJ 5719 거의 최단 경로
    https://www.acmicpc.net/problem/5719
*/

#include <bits/stdc++.h>

#define MAX 501
#define INF 987654321

using namespace std;

int n, m;
vector<pair<int, int>> adj[MAX];
vector<pair<int, int>> shortest[MAX];  // 최단경로 저장할 벡터
bool visited[MAX][MAX];                // BFS 를 위한 배열

vector<int> dijkstra(int start, int size) {
    vector<int> dist(size, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;  // 비용, 노드 번호
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;  // 최단 거리가 아닐때

        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i].first;
            int next_dist = cost + adj[cur][i].second;

            if (adj[cur][i].second == -1) continue;  // 삭제된 거리 제외

            if (dist[next] > next_dist) {  // 최단 거리 찾았을때
                dist[next] = next_dist;
                pq.push({-next_dist, next});  // 음수로 넣어야 순서를 맞춤

                shortest[next].clear();
                shortest[next].push_back({cur, next_dist});
            } else if (dist[next] == next_dist) {
                shortest[next].push_back({cur, next_dist});
            }
        }
    }

    return dist;
}

void bfs(int dest) {
    queue<int> q;

    q.push(dest);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < shortest[cur].size(); ++i) {
            int next = shortest[cur][i].first;
            if (visited[cur][next]) continue;

            visited[cur][next] = true;

            for (int j = 0; j < adj[next].size(); ++j) {
                if (adj[next][j].first == cur) {
                    adj[next][j].second = -1;
                }
            }

            q.push(next);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        memset(shortest, 0, sizeof(shortest));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < MAX; ++i) adj[i].clear();

        int start, dest;
        cin >> start >> dest;

        for (int i = 0; i < m; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
        }

        dijkstra(start, n);  // 최단경로를 먼저 구함

        bfs(dest);  // 먼저 구한 최단경로를 지움

        vector<int> result = dijkstra(start, n);  // 최단경로가 아닌 값들을 찾아냄

        if (result[dest] == INF)
            cout << "-1\n";
        else
            cout << result[dest] << "\n";
    }

    return 0;
}
