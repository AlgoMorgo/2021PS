#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n;
int arr[1000001];


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n;
	memset(arr, -1, sizeof(arr));
	stack<pair<int ,int>> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;

		if (s.empty()) s.push({ x, i });
		else {
			while (!s.empty()) {
				if (s.top().first < x) {
					arr[s.top().second] = x;
					s.pop();
				}
				else break;
			}
			s.push({ x, i });
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}


	return 0;
}