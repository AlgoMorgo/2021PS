#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int R, C;
string arr[1501];
bool visited[1501][1501];
vector<pair<int, int>> target;
queue<pair<int, int>> v;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'L') {
				target.push_back({ j, i });
				arr[i][j] = '.';
				v.push({ j, i });
			}
			else if (arr[i][j] == '.') v.push({ j, i });
		}
	}

	queue<pair<int, int>> q;
	int ans = 0;
	q.push(target[0]);
	visited[target[0].second][target[0].first] = true;
	while (true) {
		queue<pair<int, int>> next;
		while (!q.empty()) {
			int r = q.front().second;
			int c = q.front().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + c;
				int ny = dy[i] + r;
				if (nx < 0 || ny < 0 || nx >= C || ny >= R || visited[ny][nx]) continue;
				else if (target[1] == make_pair(nx, ny)) {
					cout << ans;
					return 0;
				}
				else if (arr[ny][nx] == 'X') next.push({ nx, ny });
				else q.push({ nx ,ny });
				visited[ny][nx] = true;
			}
		}
		q = next;
		ans++;

		int n = v.size();
		while(n--) {
			int r = v.front().second;
			int c = v.front().first;
			v.pop();
			for (int j = 0; j < 4; j++) {
				int nx = dx[j] + c;
				int ny = dy[j] + r;
				if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
				else if (arr[ny][nx] == 'X') {
					v.push({ nx, ny });
					arr[ny][nx] = '.';
				}
			}
		}
	}

	
	return 0;
}

