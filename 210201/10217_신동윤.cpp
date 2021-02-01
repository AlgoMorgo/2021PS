/*
    BOJ 10217 KCM Travel
    https://www.acmicpc.net/problem/10217
*/

#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

struct Info {
    int destination, cost, time;
    bool operator<(const Info& info) const {
        if (this->time == info.time) return this->cost > info.cost;
        return this->time > info.time;
    }
};

int t;
int dp[101][10001];  // dp[i][j] = k : i 번노드 까지 j 의 비용으로 갔을때 최소시간 k
vector<Info> adj[101];

int dijkstra(int nodes, int money) {  // 전체 노드 갯수, 총 비용
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j <= money; ++j) {
            dp[i][j] = INF;
        }
    }

    priority_queue<Info> pq;
    pq.push({0, 0, 0});
    dp[0][0] = 0;

    while (!pq.empty()) {
        Info temp = pq.top();
        pq.pop();

        int _cost = temp.cost, _time = temp.time, _destination = temp.destination;

        if (_destination == nodes - 1) break;

        dp[_destination][_cost] = _time;

        for (int i = 0; i < adj[_destination].size(); ++i) {
            Info& next = adj[_destination][i];

            if (_cost + next.cost > money) continue;                                     // 총 비용을 넘기면 못하는것
            if (dp[next.destination][_cost + next.cost] <= _time + next.time) continue;  // 최소 비용으로 거르기 위한 용도

            pq.push((Info){next.destination, _cost + next.cost, _time + next.time});
            dp[next.destination][_cost + next.cost] = _time + next.time;
        }
    }

    int result = INF;
    for (int i = 0; i <= money; ++i)
        result = min(result, dp[nodes - 1][i]);  // 최소 시간
    return result;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 0; i < n; ++i) adj[i].clear();

        for (int i = 0; i < k; ++i) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u - 1].push_back({v - 1, c, d});
        }
        int result = dijkstra(n, m);
        if (result < INF)
            cout << result << "\n";
        else
            cout << "Poor KCM\n";
    }

    return 0;
}
Colored