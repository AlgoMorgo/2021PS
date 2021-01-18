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
	int x, y, p, q;
	info(int x = 0, int y = 0) : x(x), y(y), p(1), q(0) {}
};
int n;
pair<int, int> target;
vector<info> arr;

bool cmp(info& a, info& b) {
	if (1LL * a.q * b.p != 1LL * a.p * b.q) return 1LL * a.q * b.p < 1LL * a.p * b.q;

	if (a.y != b.y) return a.y < b.y;

	return a.x < b.x;
}

long long ccw(info& a, info& b, info& c) {
	long long t = 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * b.x * a.y - 1LL * c.x * b.y - 1LL * a.x * c.y;
	if (t > 0) return 1;
	else if (t == 0) return 0;
	else return -1;
}

bool isInside(pair<int, int>& target, stack<int> S) {
	int first = S.top(); S.pop();
	int start = first;
	int second = S.top(); S.pop();
	info P(target.first, target.second);
	int direct = ccw(arr[first], arr[second], P);
	while (!S.empty())
	{
		first = second;
		second = S.top();
		S.pop();
		if (direct != ccw(arr[first], arr[second], P)) return false;
	}
	if (direct != ccw(arr[second], arr[start], P)) return false;
	return true;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> target.first >> target.second;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(info(a, b));
	}
	int ans = 0;


	while (arr.size() >= 3) {
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 1; i < arr.size(); i++) {
			arr[i].p = arr[i].x - arr[0].x;
			arr[i].q = arr[i].y - arr[0].y;
		}
		sort(arr.begin() + 1, arr.end(), cmp);

		stack<int> S;
		S.push(0);
		S.push(1);

		int next = 2;

		while (next < arr.size()) {
			while (S.size() >= 2) {
				int second = S.top();
				S.pop();
				int first = S.top();

				// 좌회전(ccw > 0)이면 second push 아니면 계속 진행
				if (ccw(arr[first], arr[second], arr[next]) > 0) {
					S.push(second);
					break;
				}
			}
			S.push(next++);
		}
		if (!isInside(target, S)) break;
		ans++;
		while (!S.empty()) {
			for (auto iter = arr.begin(); iter != arr.end();) {
				if (iter->x == arr[S.top()].x && iter->y == arr[S.top()].y) {
					iter = arr.erase(iter);
					break;
				}
				else iter++;
			}
			S.pop();
		}
	}
	cout << ans;

	return 0;
}