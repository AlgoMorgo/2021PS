#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m, k, cnt;
int arr[10001];
vector<int> adj[10001];
bool visited[10001];

void dfs(int d) {
	visited[d] = true;

	cnt = min(cnt, arr[d]);

	for (int x : adj[d]) {
		if (!visited[x]) dfs(x);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int j = 0; j < m; j++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt = 10001;
			dfs(i);
			ans += cnt;
		}
	}
	if (ans > k) cout << "Oh no\n";
	else cout << ans;

	return 0;
}