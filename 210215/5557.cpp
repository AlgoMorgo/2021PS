#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int n;
long long dp[101][21];
int arr[101];

long long dfs(int d,int cnt) {
	if (d == n - 1) {
		if (cnt == arr[d]) return 1;
		else return 0;
	}

	long long& ret = dp[d][cnt];
	if (ret != 0) return ret;

	if (cnt + arr[d] <= 20) ret += dfs(d + 1, cnt + arr[d]);
	if (cnt - arr[d] >= 0) ret += dfs(d + 1, cnt - arr[d]);

	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << dfs(1, arr[0]);


	return 0;
}