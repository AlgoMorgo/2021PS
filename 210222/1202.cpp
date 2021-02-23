#include <bits/stdc++.h>
using namespace std;

pair<int, int> v[300001];
multiset<int> bag;

bool cmp(pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; }

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		bag.insert(a);
	}

	sort(v, v + n, cmp);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto iter = bag.lower_bound(v[i].first);
		if (iter != bag.end()) {
			ans += v[i].second;
			bag.erase(iter);
		}
	}

	cout << ans;


	return 0;
}