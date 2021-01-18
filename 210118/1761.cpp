#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

vector<pair<int, int>> adj[40001];
int n, m;
int dp[40001][17]; //
int depth[40001];
int dist[40001];
bool visited[40001];


void dfs(int cur, int d, int cost) {
	visited[cur] = true;
	depth[cur] = d;
	dist[cur] = cost;
	for (auto x : adj[cur]) {
		int next = x.first;
		int c = x.second;

		if (visited[next]) continue;
		dp[next][0] = cur;
		dfs(next, d + 1, cost + c);
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v); // u가 무조건 부모노드
	int diff = depth[v] - depth[u];
	for (int i = 0; diff; i++) {
		if (diff & 1) v = dp[v][i]; // 높이 차이가 홀수면 이동
		diff >>= 1;
	}
	if (u == v) return u;
	for (int i = 16; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	dfs(1, 0, 0);
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dist[a] + dist[b] - 2 * dist[lca(a,b)] << '\n';
	}


	return 0;
}