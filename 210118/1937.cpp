#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int n;
int Map[501][501];
int dp[501][501];


int dfs(int x, int y) {

	int& ret = dp[y][x];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || Map[y][x] >= Map[ny][nx]) continue;

		ret = max(ret, dfs(nx, ny) + 1);
	}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	//fstream fs("1.in");

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> Map[i][j];

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dfs(j, i));
		}
	}

	cout << ans + 1;

	return 0;
}
