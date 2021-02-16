#include <bits/stdc++.h>

using namespace std;
int n, m;
int sum[101];
int dp[101][51];



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		sum[i] = x + sum[i - 1];
	}

	for (int j = 1; j <= m; j++) {
		dp[0][j] = -3276800;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= i; k++) {
				if (k >= 2)
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
				else if (k == 1 && j == 1)
					dp[i][j] = max(dp[i][j], sum[i]);
			}
		}
	}

	cout << dp[n][m];

	return 0;
}

