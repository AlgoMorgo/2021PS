#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, k;
set<int> s;
vector<int> v;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; s.insert(x);
	}
	n = s.size();
	for (auto iter = s.begin(); iter != s.end(); iter++) v.push_back(*iter);

	for (int i = 0; i < n - 1; i++) {
		v[i] = v[i + 1] - v[i];
	}

	sort(v.begin(), v.begin() + n - 1);
	long long ans = 0;
	for (int i = 0; i < n - k; i++) ans += v[i];

	cout << ans;
	return 0;
}
