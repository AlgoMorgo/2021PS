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
	// 액자에 들어간 사진 수 저장
	int pictureNum = 0;
	for (int i = 0; i < M; i++) {
		//액자가 꽉 차지 않은 경우
		if (pictureNum < N) {
			// 액자 배열 내부에 해당하는 사진이 존재하는지 확인하는 변수
			bool isExist = false;
			for (int j = 0; j < pictureNum; j++) {
				// 액자 배열 내부에 해당 사진이 존재하는 경우
				if (recommend[i] == picture[j].second.second) {
					picture[j].first++;
					student[recommend[i]]++;
					isExist = true;
				}
				picture[j].second.first--;
			}
			//액자 배열 내부에 해당 사진이 존재하지 않는 경우
			if (!isExist) {
				student[recommend[i]]++;
				picture[pictureNum++] = make_pair(student[recommend[i]], make_pair(0, recommend[i]));
			}

		}
		//액자가 꽉 찬 경우
		else {
			bool isExist = false;
			student[recommend[i]]++;
			// 액자에 사진이 이미 존재하는 경우
			for (int j = 0; j < N; j++) {
				if (recommend[i] == picture[j].second.second) {
					picture[j].first++;
					isExist = true;
				}
				picture[j].second.first--;
			}
			//존재하지 않는 경우
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
