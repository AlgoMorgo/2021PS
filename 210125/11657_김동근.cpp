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
struct info {
	int from, to, cost;
};
vector<info> v(6001);
vector<long long> dist(501, INT64_MAX);
int n, m;

bool Bellman_Ford() {
	dist[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[v[j].from] == INT64_MAX) continue;
			else if (dist[v[j].to] > dist[v[j].from] + v[j].cost) {
				dist[v[j].to] = dist[v[j].from] + v[j].cost;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (dist[v[i].from] == INT64_MAX) continue;
		if (dist[v[i].to] > dist[v[i].from] + v[i].cost) {
			cout << -1;
			return false;
		}
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = { a,b,c };
	}

	if (Bellman_Ford()) {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INT64_MAX) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}