#include <bits/stdc++.h>
using namespace std;

int n, c;
pair<int, int> v[300001];
int dp[300001];

bool cmp(pair<int, int>&a, pair<int, int>& b){
	return a.first == b.first ? a.second > b.second : a.first < b.first;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	sort(v, v + n, cmp);

	dp[0] = v[0].second;
	int prev = 0;

	for (int i = 1; i < n; i++) {
		for (int j = prev; v[j].first + c <= v[i].first; j++) {
			if (dp[i] < dp[j] + v[i].second) {
				prev = j;
				dp[i] = dp[j] + v[i].second;
			}
		}
		dp[i] = max(dp[i], v[i].second);
	}
	cout << *max_element(dp, dp + n);

	return 0;
}