#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int n, m, visited[200001], c=  1;
vector<int> adj[200001];
queue<pair<int, int>> q;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		while (true) {
			cin >> x;
			if (x) adj[i].push_back(x);
			else break;
		}
	}
	memset(visited, -1, sizeof(visited));
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		visited[x] = 0;
		for (int i = 0; i < adj[x].size(); i++) q.push({ x, adj[x][i] });
	}
	while (!q.empty()) {
		queue<pair<int, int>> Q;
		vector<pair<int, int>> v;
		while (!q.empty()) {
			int now = q.front().second;
			int pre = q.front().first;
			q.pop();

			if (visited[now] != -1) continue;

			int cnt = 0;
			for (int i = 0; i < adj[now].size(); i++) {
				if (visited[adj[now][i]] != -1) cnt++;
			}
			if ((adj[now].size() + 1) / 2 <= cnt) {
				v.push_back({ now, visited[pre] + 1 });
				for (int i = 0; i < adj[now].size(); i++) {
					if (visited[adj[now][i]] == -1) Q.push({ now, adj[now][i] });
				}
			}
		}
		for (auto x : v) visited[x.first] = x.second;
		while (!Q.empty()) {
			q.push(Q.front()); Q.pop();
		}
	}

	for (int i = 1; i <= n; i++) cout << visited[i] << ' ';

	return 0;
}