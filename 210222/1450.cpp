#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, c;
int arr[31];

vector<long long> Left;
vector<long long> Right;
vector<int> l;
vector<int> r;

void dfs(int d, long long cnt, bool flag) {
	if (flag && d == l.size()) {
		Left.push_back(cnt);
		return;
	}
	else if (!flag && d == r.size()) {
		Right.push_back(cnt);
		return;
	}

	if (flag) dfs(d + 1, cnt + l[d], flag);
	else dfs(d + 1, cnt + r[d], flag);

	dfs(d + 1, cnt, flag);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i < (n / 2)) l.push_back(x);
		else r.push_back(x);
	}

	dfs(0, 0, true);
	dfs(0, 0, false);

	sort(Right.begin(), Right.end());
	sort(Left.begin(), Left.end());

	long long ans = 0;
	for (int i = 0; i < Left.size(); i++) {
		auto iter = upper_bound(Right.begin(), Right.end(), c - Left[i]);
		if (iter != Right.begin()) {
			ans += iter - Right.begin();
		}
	}

	cout << ans;

	return 0;
}

