/*
Ǯ�� : ��õ Ƚ��, ������ �����ϸ鼭 �켱������ ���� ���� ��� ��ü
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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	vector<pair<pair<int, int>, int>>v; // ��ȣ, ��õ Ƚ��, �� ����

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		if (v.size() < n) {
			bool check = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j].first.first == x) { // �̹� ���ڿ� ������ ��õ Ƚ�� �߰�
					check = true;
					v[j].first.second++;
					break;
				}
			}
			if (!check) { // ���ڿ� ������ �߰�
				v.push_back({ {x, 1},i });
			}
		}
		else {
			int rating = 1001, index = 1001, age = 1001;
			bool check = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j].first.first == x) { // �̹� ���ڿ� ������ ��õ Ƚ�� �߰�
					check = true;
					v[j].first.second++;
					break;
				}
				else if (v[j].first.second < rating) { // ���� ��õ Ƚ�� �˻�
					rating = v[j].first.second;
					age = v[j].second;
					index = j;
				}
				else if (v[j].first.second == rating && v[j].second < age) { // ��õ Ƚ���� ������ �� ���� �˻�
					rating = v[j].first.second;
					age = v[j].second;
					index = j;
				}
			}
			if (!check) { // ��ü
				v[index] = { {x, 1}, i };
			}
		}
	}

	vector<int> ans;
	for (auto x : v) ans.push_back(x.first.first);

	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << ' ';

	return 0;
}
