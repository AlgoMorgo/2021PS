#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m;
bool visited[51][51];
string arr[51];
struct info { int x, y, c; };

int bfs(int x, int y) {
	memset(visited, false, sizeof(visited));
	queue<info>q;
	q.push({ x,y,0 });
	visited[y][x] = true;
	
	int cnt = 0;
	while (!q.empty()) {
		info now = q.front();
		q.pop();

		cnt = max(cnt, now.c);

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now.x;
			int ny = dy[i] + now.y;

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] || arr[ny][nx] == 'W') continue;
			visited[ny][nx] = true;
			q.push({ nx ,ny , now.c + 1 });
		}
		
	}
	return cnt;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				ans = max(ans, bfs(j, i));
			}
		}
	}

	cout << ans;

	return 0;
}