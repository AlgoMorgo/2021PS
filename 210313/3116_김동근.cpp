#include <bits/stdc++.h>

const int dx[9] = {0, -1,0,1,1,1,0,-1,-1};
const int dy[9] = {0, -1,-1,-1,0,1,1,1,0};

using namespace std;
int n, M = -1, ans = 0, c[5001];
struct pos { int x, y, d; }v[5001];
map<int, int>m;

struct Data { int cnt, from, to; };
vector<Data> arr;

bool cmp(Data& a, Data& b) {
	return a.cnt < b.cnt;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y >> v[i].d;
	}


	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int diffx = dx[v[i].d] - dx[v[j].d];
			int diffy = dy[v[i].d] - dy[v[j].d];

			if (diffx == 0 && diffy == 0) continue;
			else if (diffx == 0 && (v[i].x != v[j].x)) continue;
			else if (diffy == 0 && (v[i].y != v[j].y)) continue;
			else if (diffx == 0) {
				if ((v[i].y - v[j].y) % diffy != 0) continue;
				else {
					int temp = abs((v[i].y - v[j].y) / diffy);
					arr.push_back({ temp, i, j });
				}
			}
			else if (diffy == 0) {
				if ((v[i].x - v[j].x) % diffx != 0) continue;
				else {
					int temp = abs((v[i].x - v[j].x) / diffx);
					arr.push_back({ temp, i, j });
				}
			}
			else if ((v[i].y - v[j].y) % diffy != 0) continue;
			else if ((v[i].x - v[j].x) % diffx != 0) continue;
			else if (abs((v[i].y - v[j].y) / diffy) != abs((v[i].x - v[j].x) / diffx))continue;
			else {
				int temp = abs((v[i].x - v[j].x) / diffx);
				arr.push_back({ temp, i, j });
			}
		}
	}

	sort(arr.begin(), arr.end(), cmp);
	int idx = 0;

	while (idx < arr.size()) {
		memset(c, 0, sizeof(c));
		int pre = arr[idx].cnt;
		vector<int> posArr;
		while (idx < arr.size() && pre == arr[idx].cnt) {
			posArr.push_back(arr[idx].from);
			posArr.push_back(arr[idx].to);
			c[arr[idx].from]++;
			c[arr[idx].to]++;
			idx++;
		}

		sort(posArr.begin(), posArr.end());
		posArr.erase(unique(posArr.begin(), posArr.end()), posArr.end());
		for (int now : posArr) {
			if (M < c[now] + 1) {
				M = c[now] + 1;
				ans = pre;
			}
		}
	}

	cout << M << '\n' << ans;

	return 0;
}

