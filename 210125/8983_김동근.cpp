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
int n, m, l;
vector<int> attack(100001);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++) {
		cin >> attack[i];
	}
	// ��� ��ġ�� �������� ����
	sort(attack.begin(), attack.begin() + m);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		// x��ǥ�� �������� ���� ����� ��븦 ã��
		auto iter = lower_bound(attack.begin(), attack.begin() + m, x);
		// ó���� �ƴϸ� ���� �ε����� ��
		if (iter != attack.begin()) {
			if (abs(*(iter - 1) - x) + y <= l) {
				ans++;
				continue;
			}
		}
		// ���� �ƴϸ� ���� �ε����� ��
		if (iter != attack.begin() + m) {
			if (abs(*iter - x) + y <= l) ans++;
		}
	}
	cout << ans;
	
	return 0;
}