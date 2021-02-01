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

string arr[5];
set<pair<int, int>> s;
int ans = 0;

void solve(vector<int>& v) {
	set<int> temp;
	for (int x : v) temp.insert(x);

	queue<int> q;
	bool visited[5][5] = { false, };
	q.push(v[0]);
	visited[v[0] / 5][v[0] % 5] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front() % 5;
		int y = q.front() / 5;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[ny][nx]) continue;
			else if (temp.count(ny * 5 + nx) == 1) {
				visited[ny][nx] = true;
				cnt++;
				q.push({ ny * 5 + nx });
			}
		}
	}

	if (cnt == 7) ans++;
}

void permutation(int d, vector<int>& v) {
	int len = v.size();
	if (len >= 4) {
		int c = 0;
		for (int i = 0; i < len; i++) {
			int x = v[i] % 5;
			int y = v[i] / 5;
			if (s.count({ x ,y }) == 0) c++;
		}
		if (c >= 4) return;
	}

	if (len == 7) {
		
		solve(v);
		return;
	}
	else if (d == 25) return;
	else {
		v.push_back(d);
		permutation(d + 1, v);
		v.pop_back();
		permutation(d + 1, v);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 'S') s.insert({ j, i }); // x y
		}
	}

	vector<int> t;
	permutation(0, t);

	cout << ans;
	return 0;
}
