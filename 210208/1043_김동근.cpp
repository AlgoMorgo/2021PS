#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m, k;
set<int> s;
vector<int> v[51];
vector<bool> check(51, true);


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < m; i++) {
		int x,t; cin >> t;
		while (t--) {
			cin >> x;
			v[i].push_back(x);
		}
	}

	while (true) {
		bool c = false;

		for (int i = 0; i < m; i++) {
			bool C = false;
			for (int j = 0; j < v[i].size(); j++) {
				if (check[i] && s.count(v[i][j]) != 0) {
					check[i] = false;
					C = true;
					break;
				}
			}
			if (C) {
				c = true;
				for (int j = 0; j < v[i].size(); j++) {
					s.insert(v[i][j]);
				}
			}
		}

		if (!c) break;
	}

	int ans = 0;
	for (int i = 0; i < m; i++) if (check[i]) ans++;
	cout << ans;




	return 0;
}

