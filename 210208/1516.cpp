#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n;
int arr[501];
int original[501];
vector<int> v[501];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		arr[i] = x;
		original[i] = x;
		while (true) {
			cin >> x;
			if (x == -1) break;
			v[i].push_back(x);
		}
	}

	while (true) {
		bool c = false;
		for (int i = 1; i <= n; i++) {
			int M = 0;
			for (int j = 0; j < v[i].size(); j++) {
				M = max(M, arr[v[i][j]]);
			}
			if (arr[i] != original[i] + M) {
				c = true;
				arr[i] = original[i] + M;
			}
		}
		if (!c) break;
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << '\n';

	return 0;
}