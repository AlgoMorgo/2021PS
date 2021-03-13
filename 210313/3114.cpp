#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int R, C, apple[1502][1502], banana[1502][1502];
int dp[1502][1502];

int dfs(int r, int c) {
	if (r == R && c == C) return 0;

	int& ret = dp[r][c];
	if (ret != -1) return ret;

	if(r + 1 <= R)
		ret = max(ret, dfs(r + 1, c) + apple[r + 1][c - 1]);
	if (c + 1 <= C)
		ret = max(ret, dfs(r, c + 1) + banana[r - 1][c + 1]);
	if (r + 1 <= R && c + 1 <= C)
		ret = max(ret, dfs(r + 1, c + 1) + apple[r + 1][c] + banana[r][c + 1]);

	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			string x;
			cin >> x;
			int b = 0, a = 0;
			x[0] == 'B' ? b = stoi(x.substr(1, -1)) : a = stoi(x.substr(1, -1));
			apple[i][j] = apple[i][j - 1] + a;
			banana[i][j] = banana[i - 1][j] + b;
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 1);

	return 0;
}
