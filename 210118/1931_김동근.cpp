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
int N;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

pair<int, int> Map[100000];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) cin >> Map[i].first >> Map[i].second;

	sort(Map, Map + N, cmp);


	int ans = 0;
	int now = 0;
	for (int i = 0; i < N; i++) {
		if (now <= Map[i].first) {
			now = Map[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}