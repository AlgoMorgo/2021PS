/*
    BOJ 16681 등산
    https://www.acmicpc.net/problem/16681
*/

#include <bits/stdc++.h>

#define INF LLONG_MAX
#define MAX 100001

using namespace std;

typedef long long ll;

int N, M, D, E;
vector<int> height;               // 높이 저장을 위한 벡터
vector<pair<int, int>> adj[MAX];  // 연결지점, 거리

ll dijkstra() {
    // 집에서 특정 지점 까지의 거리
    vector<ll> dist1(N + 1, INF);
    priority_queue<pair<ll, int>> pq;  // 거리, 노드 번호
    pq.push({0, 1});

    while (!pq.empty()) {
        ll distance = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (distance > dist1[cur]) continue;  // 최단거리가 아닐때

        for (int i = 0; i < adj[cur].size(); ++i) {
            ll next_dist = adj[cur][i].second + distance;
            int next_node = adj[cur][i].first;

            if (dist1[next_node] > next_dist && height[next_node] > height[cur]) {
                // 집에서 어떤 지점까지는 항상 높이가 증가하는 방향으로 처리되야하고, 최단거리를 갱신해야함.
                dist1[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    // 목적지인 고려대에서 어떤 지점까지의 거리 구하기
    vector<ll> dist2(N + 1, INF);
    pq.push({0, N});

    while (!pq.empty()) {
        ll distance = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (distance > dist2[cur]) continue;

        for (int i = 0; i < adj[cur].size(); ++i) {
            ll next_dist = adj[cur][i].second + distance;
            int next_node = adj[cur][i].first;

            if (dist2[next_node] > next_dist && height[next_node] > height[cur]) {
                dist2[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    ll value = -INF;
    for (int i = 2; i < N; ++i) {
        if (dist1[i] == INF || dist2[i] == INF) continue;  // 경로가 없는 경우 패스함.

        ll tmp = height[i] * E - (dist1[i] + dist2[i]) * D;  // 높이 * 성취감 - 거리당 소모된 체력
        value = max(value, tmp);
    }

    return value;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> D >> E;

    height.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> height[i];
    }

    for (int i = 0; i < M; ++i) {
        int a, b, n;
        cin >> a >> b >> n;
        adj[a].push_back({b, n});  // 양방향 경로라 했으므로 둘다 이어줌
        adj[b].push_back({a, n});
    }

    ll temp = dijkstra();
    if (temp == -INF)
        cout << "Impossible";
    else
        cout << temp;

    return 0;
}
