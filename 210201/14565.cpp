#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
long long n, a;

long long gcd(long long  x, long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> a;

	cout << n - a << ' ';

	if (gcd(n, a) != 1) cout << -1;
	else {
		vector<long long> s, t, r, q;
		s = { 1, 0 };
		t = { 0, 1 };
		r = { a, n };

		while (true) {
			long long r2 = r[r.size() - 2];
			long long r1 = r[r.size() - 1];
			q.push_back(r2 / r1);
			r.push_back(r2 % r1);

			if (r[r.size() - 1] == 0) break;

			long long s2 = s[s.size() - 2];
			long long s1 = s[s.size() - 1];

			long long t2 = t[t.size() - 2];
			long long t1 = t[t.size() - 1];

			long long q1 = q[q.size() - 1];
			s.push_back(s2 - s1 * q1);
			t.push_back(t2 - t1 * q1);
		}

		cout << (s[s.size() - 1] + n) % n;
	}


	return 0;
}
