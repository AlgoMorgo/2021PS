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
#include <fstream>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int n, d, k, c;
vector<int> arr(3000001);
vector<int> visited(3000001);


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 1;
	visited[c]++;
	for (int i = 0; i < k; i++) {
		visited[arr[i]]++;
		if (visited[arr[i]] == 1) cnt++;
	}

	int ans = cnt;

	for (int i = 0; i < n - 1; i++) {
		visited[arr[i]]--;
		if (visited[arr[i]] == 0) cnt--;
		visited[arr[(i + k) % n]]++;
		if (visited[arr[(i + k) % n]] == 1) cnt++;

		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}