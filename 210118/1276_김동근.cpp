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
int n;

struct info {
	int y, x1, x2;
};
bool cmp(info& a, info& b) {
	return a.y > b.y;
}
vector<info> v;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c - 1 });
	}

	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		bool x1 = false;
		bool x2 = false;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].x1 >= v[j].x1 && v[i].x1 <= v[j].x2 && !x1) {
				x1 = true;
				ans += v[i].y - v[j].y;
			}
			if (v[i].x2 >= v[j].x1 && v[i].x2 <= v[j].x2 && !x2) {
				x2 = true;
				ans += v[i].y - v[j].y;
			}
			if (x1 && x2) break;
		}
		if (!x1) ans += v[i].y;
		if (!x2) ans += v[i].y;
	}
	ans += v[v.size() - 1].y * 2;
	cout << ans;

	return 0;
}