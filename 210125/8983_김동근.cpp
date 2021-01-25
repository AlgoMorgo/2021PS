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
	// 사대 위치를 오름차순 정렬
	sort(attack.begin(), attack.begin() + m);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		// x좌표를 기준으로 가장 가까운 사대를 찾음
		auto iter = lower_bound(attack.begin(), attack.begin() + m, x);
		// 처음이 아니면 이전 인덱스와 비교
		if (iter != attack.begin()) {
			if (abs(*(iter - 1) - x) + y <= l) {
				ans++;
				continue;
			}
		}
		// 끝이 아니면 현재 인덱스와 비교
		if (iter != attack.begin() + m) {
			if (abs(*iter - x) + y <= l) ans++;
		}
	}
	cout << ans;
	
	return 0;
}