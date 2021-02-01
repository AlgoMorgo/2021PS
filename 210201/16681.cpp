#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m, d, e;
vector<int> height(100001);
vector<pair<int, int>> adj[100001];

void solve(int start, vector<long long>& dist) {
	priority_queue<pair<long long, int>> pq;
	dist[start] = 0;
	pq.emplace( 0, start );
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost > dist[now]) continue;

		for (auto x : adj[now]) {
			int next = x.second;
			int ncost = x.first;

			if (height[now] < height[next] && dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				pq.emplace( -dist[next], next );
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m >> d >> e;

	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (height[a] > height[b]) swap(a, b);
		adj[a].emplace_back( c, b );
	}


	vector<long long> dist1(100001, INT64_MAX);
	vector<long long> dist2(100001, INT64_MAX);
	solve(1, dist1);
	solve(n, dist2);

	long long ans = INT64_MIN;
	for (int i = 2; i < n; i++) {
		if (dist1[i] == INT64_MAX || dist2[i] == INT64_MAX) continue;
		ans = max(ans, (long long)height[i] * e - (dist1[i] + dist2[i]) * d);
	}

	if (ans == INT64_MIN) cout << "Impossible\n";
	else cout << ans;

	return 0;
}
