#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int> v(100001);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> v[i];

	int l = *max_element(v.begin(), v.end());
	int r = 1000000000;
	int k = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int i = 0;
		int cnt = 0;
		while (i < n) {
			int sum = 0;
			int value = mid;
			cnt++;
			while (i < n && v[i] <= value) {
				value -= v[i++];
			}
		}

		if (cnt <= m) {
			k = mid;
			r = mid - 1;
		}
		else l = mid + 1;

	}
	cout << k << '\n';

	return 0;
}
