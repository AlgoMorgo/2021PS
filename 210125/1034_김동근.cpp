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
#include <time.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m, k;
string arr[51];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> k;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++)
			if (arr[i][j] == '0') cnt++;

		int s = 0;
		if (cnt <= k && cnt % 2 == k % 2) {
			for (int j = 0; j < n; j++) {
				if (arr[i] == arr[j]) s++;
			}
		}
		ans = max(ans, s);
	}
	cout << ans;

	return 0;
}