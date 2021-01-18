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
	int x, y;
	double win, draw, lose;
};

map<string, int> m;
info arr[6];
int score[4];
double winRate[4];


void dfs(int d, double p) {

	if (d == 6) {
		pair<int, int>temp[4];
		for (int i = 0; i < 4; i++) {
			temp[i].first = score[i];
			temp[i].second = i;
		}
		sort(temp, temp + 4);
		if (temp[1].first != temp[2].first) { // 1,2등이 확실할 경우
			winRate[temp[2].second] += p;
			winRate[temp[3].second] += p;
		}
		else if (temp[0].first == temp[1].first && temp[1].first == temp[2].first && temp[2].first == temp[3].first) { //0 == 1==2==3
			winRate[temp[0].second] += p * (1 / 2.0); winRate[temp[1].second] += p * (1 / 2.0);
			winRate[temp[2].second] += p * (1 / 2.0); winRate[temp[3].second] += p * (1 / 2.0);
		}
		else if (temp[1].first == temp[2].first && temp[2].first == temp[3].first) { // 0 < 1 == 2 == 3
			winRate[temp[1].second] += p * (2 / 3.0); winRate[temp[2].second] += p * (2 / 3.0); winRate[temp[3].second] += p * (2 / 3.0);
		}
		else if (temp[0].first == temp[1].first && temp[1].first == temp[2].first) { // 0 == 1 == 2 < 3
			winRate[temp[3].second] += p; winRate[temp[0].second] += p * (1 / 3.0); winRate[temp[1].second] += p * (1 / 3.0); winRate[temp[2].second] += p * (1 / 3.0);
		}
		else if (temp[1].first == temp[2].first) { // 0 < 1 == 2 < 3
			winRate[temp[3].second] += p; winRate[temp[1].second] += p * (1 / 2.0); winRate[temp[2].second] += p * (1 /  2.0);
		}
		return;
	}

	int x = arr[d].x, y = arr[d].y;
	score[x] += 3;
	dfs(d + 1, p * arr[d].win);
	score[x] -= 3;

	score[x] += 1; score[y] += 1;
	dfs(d + 1, p * arr[d].draw);
	score[x] -= 1; score[y] -= 1;

	score[y] += 3;
	dfs(d + 1, p * arr[d].lose);
	score[y] -= 3;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	for (int i = 0; i < 4; i++) {
		string country;
		cin >> country;
		m[country] = i;
	}

	int score[4] = { 0,0,0,0 };
	for (int i = 0; i < 6; i++) {
		string a, b;
		float w, d, l;
		cin >> a >> b >> w >> d >> l;
		arr[i] = { m[a], m[b], w,d,l };
	}

	dfs(0, 1.0);

	for (auto x : winRate) cout << x << '\n';


	return 0;
}