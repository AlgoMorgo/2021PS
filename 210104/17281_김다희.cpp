#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 51;

int T;
int hitBoard[MAX][9];

// ���� ���� ����. index ����, value ���� ��ȣ
int playerOrder[9];
int result = 0;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> hitBoard[i][j];
		}
	}

	// ���� ���� �ʱ�ȭ
	for (int i = 0; i < 9; i++) {
		playerOrder[i] = i;
	}

	
	// ��� ����� �� ��ȸ
	do {
		// 1�� ������ 4�� Ÿ�ڰ� �ƴ� ��� continue;
		if(playerOrder[3] != 0) continue;
		int score = 0;
		// Ÿ��
		int index = 9;

		for (int i = 0; i < T; i++) {
			int outScore = 0;
			// ���� ���� ����
			queue<int> base;
			while(true) {
				index = index % 9;
				int hit = hitBoard[i][playerOrder[index]];
				// �ƿ�
				if (hit == 0) {
					outScore++;
					index++;
					if (outScore > 2) {
						break;
					}
				}
				//1~3��Ÿ
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
				//Ȩ��
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