/*
* 풀이 : dp
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

string a, b;
vector<int> dp(1001); // 현재 인덱스까지의 LCS
vector<vector<int>> v; // 모든 dp배열을 담기위한 벡터

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> a >> b;

	int ans = 0;
	for (int i = 0; i < b.length(); i++) {
		vector<int> temp(1001); // 현재 상태를 담을 배열
		for (int j = 0; j < a.length(); j++) {
			if (b[i] == a[j]) {
				int MAX = 0; // 
				for (int k = 0; k < j; k++) { // 현재 인덱스 전에서 가장 긴 공통 부분 수열 찾기
					if (dp[k] <= i && MAX < dp[k]) {
						MAX = max(MAX, dp[k]);
					}
				}
				temp[j] = MAX + 1; // 이전 LCS에 +1
				ans = max(ans, temp[j]); // 가장 긴 값이 정답
			}
			else temp[j] = dp[j]; // 같지 않으면 이전 개수 그대로
		}
		dp = temp; // 현재 상태 갱신
		v.push_back(dp); // dp 배열 저장
	}
	

	if (!ans) { // 공통부분이 없으면 0
		cout << 0;
		return 0;
	}

	int idx = max_element(dp.begin(), dp.end()) - dp.begin(); // 가장 길었던 인덱스 찾기
	int value = dp[idx];
	stack<int> s;
	s.push(idx);
	for (int i = v.size() - 1; i > 0 && value > 1; i--) { // 마지막부터 역으로 올라가면서 문자열 추적
		if (v[i - 1][idx] == v[i][idx]) continue;
		value--;
		idx--;
		while (v[i - 1][idx] != value) idx--;
		s.push(idx);
	}


	cout << ans << '\n';
	while (!s.empty()) {
		cout << a[s.top()];
		s.pop();
	}

	return 0;
}
