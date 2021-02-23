#include <bits/stdc++.h>
using namespace std;


int n, l, p;
pair<int, int> v[10001];
priority_queue<int> pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	cin >> l >> p;

	sort(v, v + n);
	
	int i = 0, ans = 0;
	bool out = false;

	while (p < l) {
		while (i < n && p >= v[i].first) {
			pq.push(v[i].second);
			i++;
		}

		if (pq.empty()) {
			out = true;
			break;
		}

		p += pq.top();
		pq.pop();
		ans++;
	}

	cout << (out ? -1 : ans);

	return 0;
}