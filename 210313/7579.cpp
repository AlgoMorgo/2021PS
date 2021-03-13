#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int n, m;
pair<int, int > arr[101];
int dp[10001];



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i].first;
	for (int i = 1; i <= n; i++) cin >> arr[i].second;


	for (int i = 1; i <= n; i++) {
		for (int j = 10000; j >= arr[i].second; j--) {
			dp[j] = max(dp[j], dp[j - arr[i].second] + arr[i].first);
		}
	}

	int ans = 0;
	int M = 1e9;
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= m && M > dp[i]) {
			ans = i;
			M = dp[i];
		}
	}

	cout << ans;

	return 0;
}