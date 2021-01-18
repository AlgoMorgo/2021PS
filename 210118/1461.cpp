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
int arr[10001];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n + 1);
	int t;
	for (int i = 0; i <= n; i++) {
		if (arr[i] == 0) {
			t = i;
			break;
		}
	}

	int ans = 0;
	for (int i = 0; i < t; i += m) ans += 2 * abs(arr[i]);
	for (int i = n; i > t; i -= m) ans += 2 * abs(arr[i]);


	cout << ans - max(abs(arr[0]), abs(arr[n]));

	return 0;
}