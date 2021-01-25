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
#include <deque>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;
int n, m, back = 0;
struct info { int s, e, i; } v[500001];
set<int> ans;
deque<info> dq;

bool cmp(info a, info b) { return a.s == b.s ? (a.e > b.e) : (a.s < b.s); }

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> v[i].s >> v[i].e;
		v[i].i = i + 1;
		if (v[i].s > v[i].e) {
			back = max(back, v[i].e);
			v[i].e += n;
		}
	}

	sort(v, v + m, cmp);

	for (int i = 0; i < m; i++) {
		if (dq.empty() || dq.back().e < v[i].e) dq.push_back(v[i]);
	}
	while (!dq.empty() && dq.front().e <= back) dq.pop_front();

	for (int i = 0; i < dq.size(); i++) ans.insert(dq[i].i);
	for (int x : ans) cout << x << ' ';
	return 0;
}