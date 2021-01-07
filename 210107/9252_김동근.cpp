/*
* Ǯ�� : dp
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
vector<int> dp(1001); // ���� �ε��������� LCS
vector<vector<int>> v; // ��� dp�迭�� ������� ����

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> a >> b;

	int ans = 0;
	for (int i = 0; i < b.length(); i++) {
		vector<int> temp(1001); // ���� ���¸� ���� �迭
		for (int j = 0; j < a.length(); j++) {
			if (b[i] == a[j]) {
				int MAX = 0; // 
				for (int k = 0; k < j; k++) { // ���� �ε��� ������ ���� �� ���� �κ� ���� ã��
					if (dp[k] <= i && MAX < dp[k]) {
						MAX = max(MAX, dp[k]);
					}
				}
				temp[j] = MAX + 1; // ���� LCS�� +1
				ans = max(ans, temp[j]); // ���� �� ���� ����
			}
			else temp[j] = dp[j]; // ���� ������ ���� ���� �״��
		}
		dp = temp; // ���� ���� ����
		v.push_back(dp); // dp �迭 ����
	}
	

	if (!ans) { // ����κ��� ������ 0
		cout << 0;
		return 0;
	}

	int idx = max_element(dp.begin(), dp.end()) - dp.begin(); // ���� ����� �ε��� ã��
	int value = dp[idx];
	stack<int> s;
	s.push(idx);
	for (int i = v.size() - 1; i > 0 && value > 1; i--) { // ���������� ������ �ö󰡸鼭 ���ڿ� ����
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
