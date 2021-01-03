/*
풀이 : 추천 횟수, 시점을 조사하면서 우선순위가 낮은 것을 계속 교체
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
	
	vector<pair<pair<int, int>, int>>v; // 번호, 추천 횟수, 들어간 시점

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		if (v.size() < n) {
			bool check = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j].first.first == x) { // 이미 액자에 있으면 추천 횟수 추가
					check = true;
					v[j].first.second++;
					break;
				}
			}
			if (!check) { // 액자에 없으면 추가
				v.push_back({ {x, 1},i });
			}
		}
		else {
			int rating = 1001, index = 1001, age = 1001;
			bool check = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j].first.first == x) { // 이미 액자에 있으면 추천 횟수 추가
					check = true;
					v[j].first.second++;
					break;
				}
				else if (v[j].first.second < rating) { // 최저 추천 횟수 검사
					rating = v[j].first.second;
					age = v[j].second;
					index = j;
				}
				else if (v[j].first.second == rating && v[j].second < age) { // 추천 횟수가 같으면 들어간 시점 검사
					rating = v[j].first.second;
					age = v[j].second;
					index = j;
				}
			}
			if (!check) { // 교체
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
