#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 51;

int T;
int hitBoard[MAX][9];

// 출전 순서 저장. index 순서, value 선수 번호
int playerOrder[9];
int result = 0;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> hitBoard[i][j];
		}
	}

	// 출전 순서 초기화
	for (int i = 0; i < 9; i++) {
		playerOrder[i] = i;
	}

	
	// 모든 경우의 수 순회
	do {
		// 1번 선수가 4번 타자가 아닌 경우 continue;
		if(playerOrder[3] != 0) continue;
		int score = 0;
		// 타자
		int index = 9;

		for (int i = 0; i < T; i++) {
			int outScore = 0;
			// 진루 정보 저장
			queue<int> base;
			while(true) {
				index = index % 9;
				int hit = hitBoard[i][playerOrder[index]];
				// 아웃
				if (hit == 0) {
					outScore++;
					index++;
					if (outScore > 2) {
						break;
					}
				}
				//1~3루타
				else if (hit < 4) {
					int length = base.size();
					while (length!=0) {
						int temp = base.front();
						temp += hit;

						if (temp > 3) { 
							base.pop(); 
							score++;
						}
						else {
							base.pop();
							base.push(temp);
						}
						length--;
					}
					base.push(hit);
					index++;
				}
				//홈런
				else {
					base.push(4);
					while (!base.empty()) {
						base.pop();
						score++;
					}
					index++;
				}

			}
		}
		if (score > result) swap(score, result);
	} while (next_permutation(playerOrder, playerOrder+9));

	cout << result;
	
}