#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

const int PICTUREMAX = 21;
const int RECOMMENDMAX = 1001;

int N, M;

//first 추천 횟수, second.first 경과 시간, second.second 학생 번호
pair<int, pair<int,int>> picture[PICTUREMAX];
int recommend[RECOMMENDMAX];

int student[101] = { 0, };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> recommend[i];
	}
}

int Answer() {
	int pictureNum = 0;
	for (int i = 0; i < M; i++) {
		if (pictureNum < N) {
			bool isExist = false;
			for (int j = 0; j < pictureNum; j++) {
				if (recommend[i] == picture[j].second.second) {
					picture[j].first++;
					student[recommend[i]]++;
					isExist = true;
				}
				picture[j].second.first--;
			}
			if (!isExist) {
				student[recommend[i]]++;
				picture[pictureNum++] = make_pair(student[recommend[i]], make_pair(0, recommend[i]));
			}

		}
		else {
			bool isExist = false;
			student[recommend[i]]++;
			for (int j = 0; j < N; j++) {
				if (recommend[i] == picture[j].second.second) {
					picture[j].first++;
					isExist = true;
				}
				picture[j].second.first--;
			}
			if (!isExist) {
				sort(picture, picture + N);
				student[picture[0].second.second] = 0;
				picture[0] = make_pair(student[recommend[i]], make_pair(0, recommend[i]));
			}


		}
	}

	return pictureNum;
}

int main() {
	Input();
	int temp = Answer();

	vector<int> result;

	for(int i = 0; i < temp; i++){
		result.push_back(picture[i].second.second);
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < temp; i++) {
		cout << result[i] << ' ';
	}
}