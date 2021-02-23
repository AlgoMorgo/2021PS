#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n;
pair<int, int> arr[10031];
int dp[10041];

int day7(int s) {
	int temp = 0;
	for (int i = s - 6; i <= s; i++) temp += min(6, arr[i].second);
	return temp;
}

int day30(int s) {
	int DP[31];
	DP[0] = 0;
	for (int i = s - 29, j = 1; i <= s && j <= 30; i++, j++) {
		DP[j] = DP[j - 1] + min(arr[i].second, 6);
		if (j >= 7) {
			DP[j] = min(DP[j], DP[j - 7] + 36);
		}
	}
	return DP[30];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 30; i <= n + 29; i++) {
			cin >> arr[i].first >> arr[i].second;
			arr[i].second *= 2;
		}

		for (int i = 30; i <= n + 29; i++) {
			dp[i] = min({
					dp[i - 1] + arr[i].first + arr[i].second,
					dp[i - 1] + 3 + arr[i].second,
					dp[i - 1] + 6,
					dp[i - 7] + 36,
					dp[i - 7] + 18 + day7(i),
					dp[i - 30] + 90,
					dp[i - 30] + 45 + day30(i)
				});
		}

		cout << dp[n + 29] << '\n';
	}
	
	return 0;
}

