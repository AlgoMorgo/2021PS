/*
    BOJ 11657 타임머신
    https://www.acmicpc.net/problem/11657
*/

#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e18
using namespace std;
int n, m;
long long dist[500];
vector<pair<int, int>> adj[500];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    bool minus_cycle = false;
    fill(dist, dist + n, INF);
    dist[0] = 0;

    for (int i = 0; i < n; ++i) {  // 본래 n - 1 만큼 순회하지만, 하나 더 추가한것은 음의 사이클을 체크하기 위함임
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < adj[j].size(); ++k) {
                int next = adj[j][k].first, d = adj[j][k].second;
                if (dist[j] != INF && dist[next] > dist[j] + d) {
                    dist[next] = dist[j] + d;
                    if (i == n - 1) minus_cycle = true;
                }
            }
        }
    }

    if (minus_cycle)
        cout << "-1\n";
    else {
        for (int i = 1; i < n; ++i) {
            if (dist[i] != INF) {
                cout << dist[i] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}