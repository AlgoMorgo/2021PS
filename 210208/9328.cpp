#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

bool visited[102][102];
string arr[102];
int R, C;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> R >> C;

		arr[0].assign(C + 2, '.');
		arr[R + 1].assign(C + 2, '.');
		for (int i = 1; i <= R; i++) {
			string x; cin >> arr[i];
			arr[i] = "." + arr[i] + ".";
		}

		string x;
		cin >> x;
		for (int k = 0; k < x.length(); k++) {
			for (int i = 1; i <= R; i++)
				for (int j = 1; j <= C; j++)
					if (arr[i][j] == (char)(x[k] - ('a' - 'A'))) arr[i][j] = '.';
		}

		int ans = 0;
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		while (!q.empty()) {
			int y = q.front().second;
			int x = q.front().first;
			q.pop();

			if (visited[y][x] || x < 0 || y < 0 || x > C + 1 || y > R + 1) continue;
			else if (arr[y][x] == '$') {
				ans++;
				arr[y][x] = '.';
			}
			else if (arr[y][x] == '*' || arr[y][x] >= 'A' && arr[y][x] <= 'Z') continue;
			else if (arr[y][x] >= 'a' && arr[y][x] <= 'z') {
				for (int i = 1; i <= R; i++)
					for (int j = 1; j <= C; j++)
						if (arr[i][j] == (char)(arr[y][x] - ('a' - 'A'))) arr[i][j] = '.';
				arr[y][x] = '.';
				memset(visited, false, sizeof(visited));
				while (!q.empty()) q.pop();
				q.push({ x, y });
				continue;
			}
			visited[y][x] = true;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				q.push({ nx, ny });
			}
		}
		cout << ans << '\n';
	}

	return 0;
}

