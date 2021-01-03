/*
풀이 : 오름차순으로 정렬하고 겹칠때와 안겹칠 때 구분해서 계산
*/
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

vector<pair<int, int>> v; // 시작, 도착


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int l = v[0].first;
	int r = v[0].second;
	int len = v.size();

	for (int i = 1; i < len; i++) {
		if (v[i].first <= r && r < v[i].second) { // 두 범위가 겹치면서 기존거보다 오른쪽 범위가 더 큰 경우
			r = v[i].second;
		}
		else if (r < v[i].first) { // 기존 범위를 넘어선 경우
			ans += r - l;
			l = v[i].first;
			r = v[i].second;
		}
	}

	cout << ans + r - l;

	return 0;
}
