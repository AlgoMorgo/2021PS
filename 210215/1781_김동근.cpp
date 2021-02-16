#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> v[200001];
int parent[200001];

int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	sort(v, v + n, cmp);

	for (int i = 0; i < n; i++) {
		int c = Find(v[i].first);
		if (c != 0) ans += v[i].second;
		merge(c, c - 1);
	}

	cout << ans;

	return 0;
}
