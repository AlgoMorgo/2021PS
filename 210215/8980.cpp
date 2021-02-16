#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
struct pos { 
	int a, b, c; 
} arr[10001];
int n, c, m;

bool cmp(const pos& A, const pos& B) {
	return A.b < B.b;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> c >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
	}

	sort(arr, arr + m, cmp);
	vector<int> v(2001, c);

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int MIN = 1e9;
		for (int j = arr[i].a; j < arr[i].b; j++) MIN = min(MIN, v[j]);

		if (MIN >= arr[i].c) {
			ans += arr[i].c;
			for (int j = arr[i].a; j < arr[i].b; j++) v[j] -= arr[i].c;
		}
		else {
			ans += MIN;
			for (int j = arr[i].a; j < arr[i].b; j++) v[j] -= MIN;
		}
	}
	cout << ans;


	return 0;
}