#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;

int N;

int Answer = 0;

pair<int, int> point[MAX];

int result[MAX];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	//input
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		point[i] = make_pair(a, b);
	}

	sort(point, point+N);

	result[0] = point[0].second - point[0].first;

	int resultIndex = 0;
	pair<int, int> now = point[0];

	for (int i = 1; i < N; i++) {
		int presentFirst = point[i].first;
		int presentSecond = point[i].second;
		int prevFirst = now.first;
		int prevSecond = now.second;

		if (presentFirst <= prevSecond) {
			if (presentSecond <= prevSecond) continue;
			else {
				now.second = presentSecond;
				result[resultIndex] = now.second - now.first;

			}
		}

		else {
			resultIndex++;
			now.first = presentFirst;
			now.second = presentSecond;
			result[resultIndex] = presentSecond - presentFirst;
		}
	}

	for (int i = 0; i < resultIndex + 1; i++) {
		Answer += result[i];
	}

	cout << Answer;

}