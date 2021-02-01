#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m, k, t;
struct info { int from, cost, time; };

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<info> arr[101];
		for (int i = 0; i < k; i++) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			arr[a].push_back({ b, c, d });
		}

		vector<vector<int>> dist(101, vector<int>(10001, INT32_MAX)); // dist[now][cost]
		dist[1][0] = 0;
		priority_queue<pair<int, pair<int, int>>> pq; // 소요시간 남은비용 현재위치
		pq.push({ 0, {0, 1} });
		while (!pq.empty()) {
			int now = pq.top().second.second;
			int time = -pq.top().first;
			int cost = pq.top().second.first;
			pq.pop();

			if (time > dist[now][cost]) continue;

			for (auto x : arr[now]) {
				int next = x.from;
				int ntime = x.time;
				int ncost = x.cost;
				if (dist[next][cost + ncost] > dist[now][cost] + ntime && cost + ncost <= m) {
					dist[next][cost + ncost] = dist[now][cost] + ntime;
					pq.push({ -dist[next][cost + ncost], {cost + ncost, next} });
				}
			}
		}

		if (dist[n][m] == INT32_MAX) cout << "Poor KCM\n";
		else cout << dist[n][m] << '\n';
	}

	return 0;
}