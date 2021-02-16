#include <bits/stdc++.h>
using namespace std;

struct info {
	long long x, y, p, q;
	info(int x = 0, int y = 0) : x(x), y(y), p(0), q(0) {}
};
int n;

bool cmp(info& a, info& b) {
	if (a.q * b.p * 1LL != a.p * b.q * 1LL) return a.q * b.p * 1LL < a.p * b.q * 1LL;

	if (a.y != b.y) return a.y < b.y;

	return a.x < b.x;
}

long long ccw(info& a, info& b, info& c) {
	return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

long long Dist(info& a, info& b) {
	return 1LL * (b.x - a.x) * (b.x - a.x) + 1LL * (b.y - a.y) * (b.y - a.y);
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<info> arr;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			arr.push_back(info(a, b));
		}
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 1; i < n; i++) {
			arr[i].p = arr[i].x - arr[0].x;
			arr[i].q = arr[i].y - arr[0].y;
		}
		sort(arr.begin() + 1, arr.end(), cmp);

		stack<int> S;
		S.push(0); S.push(1);

		int next = 2;

		while (next < arr.size()) {
			while (S.size() >= 2) {
				int second = S.top();
				S.pop();
				int first = S.top();

				if (ccw(arr[first], arr[second], arr[next]) > 0) {
					S.push(second);
					break;
				}
			}
			S.push(next++);
		}

		vector<info> v;
		while (!S.empty()) {
			v.push_back(arr[S.top()]);
			S.pop();
		}

		long long ans = 0;
		info point1, point2;
		int j = 1;
		info a, b;

		int N = v.size();
		for (int i = 0; i < N; i++) {
			int i_next = (i + 1) % N;
			while (true) {
				int j_next = (j + 1) % N;

				a.x = v[i_next].x - v[i].x;
				a.y = v[i_next].y - v[i].y;

				b.x = v[j_next].x - v[j].x;
				b.y = v[j_next].y - v[j].y;

				info temp;

				if (ccw(temp, a, b) < 0) j = j_next;
				else break;
			}
			long long dist = Dist(v[i], v[j]);
			if (dist > ans) {
				ans = dist;
				point1 = v[i];
				point2 = v[j];
			}
		}
		cout << point1.x << ' ' << point1.y << ' ' << point2.x << ' ' << point2.y << '\n';
	}


	return 0;
}