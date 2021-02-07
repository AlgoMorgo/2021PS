#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int R, C, n;
string arr[101];
bool visited[101][101];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	cin >> n;
	int plus = 1;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		y = R - y;
		int x;
		if (plus == 1) {
			x = 0;
			while (x < C) {
				if (arr[y][x] == 'x') {
					arr[y][x] = '.';
					break;
				}
				else x++;
			}
		}
		else {
			x = C - 1;
			while (x >= 0) {
				if (arr[y][x] == 'x') {
					arr[y][x] = '.';
					break;
				}
				else x--;
			}
		}
		plus = -plus;

		if (!(x == -1 || x == C)) {
			vector<pair<int, int>> v;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= C || ny >= R || arr[ny][nx] == '.') continue;
				queue<pair<int, int>> q;
				memset(visited, false, sizeof(visited));
				visited[ny][nx] = true;
				v.push_back({ nx, ny });
				q.push({ nx ,ny });
				bool out = false;
				while (!q.empty()) {
					auto now = q.front();
					q.pop();

					if (now.second == R - 1) out = true;

					for (int k = 0; k < 4; k++) {
						int nnx = now.first + dx[k];
						int nny = now.second + dy[k];
						if (nnx < 0 || nny < 0 || nnx >= C || nny >= R || arr[nny][nnx] == '.' || visited[nny][nnx]) continue;
						visited[nny][nnx] = true;
						v.push_back({ nnx ,nny });
						q.push({ nnx ,nny });
					}
				}
				if (!out) break;
				else v.clear();
			}
			if (v.size() != 0) {
				sort(v.begin(), v.end(), cmp);
				int temp[101][101];
				while (true) {
					bool check = true;
					for (int j = 0; j < v.size(); j++) {
						if (find(v.begin(), v.end(), make_pair(v[j].first, v[j].second + 1)) != v.end()) continue;
						if (v[j].second + 1 == R || arr[v[j].second + 1][v[j].first] == 'x') {
							check = false; break;
						}
					}
					if (check) {
						for (int j = 0; j < v.size(); j++) {
							temp[v[j].second + 1][v[j].first] = arr[v[j].second][v[j].first];
							arr[v[j].second][v[j].first] = '.';
							v[j].second++;
						}
						for (int j = 0; j < v.size(); j++) arr[v[j].second][v[j].first] = temp[v[j].second][v[j].first];
					}
					else break;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}


