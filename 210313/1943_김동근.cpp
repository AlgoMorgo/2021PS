#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int n, t = 3, dp[50001], sum;
pair<int, int> v[101];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	while (t--) {
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> v[i].first >> v[i].second;
			sum += v[i].first * v[i].second;
		}
		memset(dp, 0, sizeof(dp));

		if (sum % 2 == 1) cout << 0 << '\n';
		else {
			dp[0] = 1;
			for (int i = 1; i <= n; i++) {
				for (int j = 50000; j >= v[i].first; j--) {
					if (dp[j - v[i].first]) {
						for (int k = 0; k < v[i].second && j + k * v[i].first <= 50000; k++) {
							dp[j + k * v[i].first] = 1;
						}
					}
				}
			}
			cout << dp[sum / 2] << '\n';
		}
	}

	return 0;
}