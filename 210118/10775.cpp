#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

int G,P;
vector<int> parent(100001);
int Find(int x) {
	if (parent[x] == x) return x;
	else {
		parent[x] = Find(parent[x]);
		return parent[x];
	}
}

void merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;

	int ans = 0;
	for (int i = 0; i < P; i++) {
		int x;
		cin >> x;

		int gate = Find(x);
		if (gate == 0) break;
		merge(gate, gate - 1);
		ans++;
	}
	cout << ans;



	return 0;
}

