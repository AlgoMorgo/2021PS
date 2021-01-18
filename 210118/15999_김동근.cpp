#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m;
string arr[2001];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int r = i + dy[k];
				int c = j + dx[k];

				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				else if (arr[i][j] != arr[r][c]) {
					cnt++;
					break;
				}
			}
		}
	}

	int ans = 1;
	for (int i = 0; i < (m * n - cnt); i++) {
		ans = (2 * ans) % 1000000007;
	}
	cout << ans;

	return 0;
}