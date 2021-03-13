#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int dp[2][501];
int visited[2][501];
int arr[501];
int result[501];
int N, T;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> T >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		int c = 0;
		for (int j = 0; j < 2; j++) {
			if (visited[j][i]) {
				visited[j][i] = 0;
				dp[j][i] = dp[j][i - 1];
			}
			else {
				if (c == 0 && dp[j][i - 1] + arr[i] <= T) {
					dp[j][i] = dp[j][i - 1] + arr[i];
					visited[j][i] = 1;
					c++;
				}
				else dp[j][i] = dp[j][i - 1];
			}
		}
		if (!c) i -= 2;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) result[j] = dp[i][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) cout << result[i] << ' ';

	return 0;
}
