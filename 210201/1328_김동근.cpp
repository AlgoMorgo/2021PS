#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, l, r;
long long dp[101][101][101];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> l >> r;

	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int L = 1; L <= l; L++) {
			for (int R = 1; R <= r; R++) {
				dp[i][L][R] = (dp[i - 1][L - 1][R] + dp[i - 1][L][R - 1] + dp[i - 1][L][R] * (i - 2)) % 1000000007;
			}
		}
	}

	cout << dp[n][l][r];

	return 0;
}

