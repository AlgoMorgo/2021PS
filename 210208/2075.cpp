#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n;
int arr[1501][1501];
int v[1501];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
		v[i] = n - 1;
	}

	for (int i = 0; i < n; i++) {
		pair<int, int> m = { -1e9 - 1, 0 };
		for (int j = 0; j < n; j++) {
			if (v[j] >= 0 && m.first < arr[v[j]][j]) {
				m.first = arr[v[j]][j];
				m.second = j;
			}
		}
		v[m.second]--;
		if (i == n - 1) cout << m.first;
	}

	return 0;
}

