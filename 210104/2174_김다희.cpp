#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX = 102;

struct Robot
{
	int x;
	int y;
	char direction;
};

struct Command 
{
	int robotId;
	char command;
	int repeat;
};

// index : robotId;
Robot robotLocation[MAX];
Command command[MAX];


int row, col, robotNum, commandNum;

int ground[MAX][MAX];

//S 위, W 왼, E 오, N 아래. 위 아래 뒤집음.
char leftRotation[4] = { 'S', 'E', 'N', 'W' };
char rightRotation[4] = { 'S', 'W', 'N', 'E' };





void Input() {
	cin >> row >> col;
	cin >> robotNum >> commandNum;

	//땅 초기화
	for (int i = 0; i < col + 2; i++) {
		for (int j = 0; j < row + 2; j++) {
			//벽인 경우 -1
			if (j == 0 || i == 0 || i == col + 1 || j == row + 1) {
				ground[i][j] = -1;
			}
			// 빈 공간인 경우 0
			else ground[i][j] = 0;
		}
	}

	for (int i = 1; i < robotNum + 1; i++) 
	{
		cin >> robotLocation[i].x >> robotLocation[i].y >> robotLocation[i].direction;
		// 공간에 로봇이 있는 경우 로봇 번호;
		ground[robotLocation[i].y][robotLocation[i].x] = i;
	}


	for (int i = 0; i < commandNum; i++) 
	{
		cin >> command[i].robotId >> command[i].command >> command[i].repeat;
	}

}

 void Answer() {
	for (int i = 0; i < commandNum; i++) {
		int robotId = command[i].robotId;
		int presentCommand = command[i].command;
		int repeat = command[i].repeat;


		if (presentCommand == 'F') {
			int y = robotLocation[robotId].y;
			int x = robotLocation[robotId].x;
			ground[y][x] = 0;
			switch (robotLocation[robotId].direction)
			{
			case 'S':
				for (int i = 0; i < repeat; i++) {
					y--;
					if (ground[y][x] == 0) continue;
					else if (ground[y][x] == -1) {
						cout << "Robot " << robotId << " crashes into the wall";
						return;
					}
					else  {
						cout << "Robot " << robotId << " crashes into robot " << ground[y][x];
						return;
					}
				}
				robotLocation[robotId].y = y;
				robotLocation[robotId].x = x;
				ground[y][x] = robotId;
				break;
			case 'N':
				for (int i = 0; i < repeat; i++) {
					y++;
					if (ground[y][x] == 0) continue;
					else if (ground[y][x] == -1) {
						cout << "Robot " << robotId << " crashes into the wall";
						return;
					}
					else {
						cout << "Robot " << robotId << " crashes into robot " << ground[y][x];
						return;
					}
				}
				robotLocation[robotId].y = y;
				robotLocation[robotId].x = x;
				ground[y][x] = robotId;
				break;
			case 'W':
				for (int i = 0; i < repeat; i++) {
					x--;
					if (ground[y][x] == 0) continue;
					else if (ground[y][x] == -1) {
						cout << "Robot " << robotId << " crashes into the wall";
						return;
					}
					else {
						cout << "Robot " << robotId << " crashes into robot " << ground[y][x];
						return;
					}
				}
				robotLocation[robotId].y = y;
				robotLocation[robotId].x = x;
				ground[y][x] = robotId;
				break;
			case 'E':
				for (int i = 0; i < repeat; i++) {
					x++;
					if (ground[y][x] == 0) continue;
					else if (ground[y][x] == -1) {
						cout << "Robot " << robotId << " crashes into the wall";
						return;
					}
					else {
						cout << "Robot " << robotId << " crashes into robot " << ground[y][x];
						return;
					}
				}
				robotLocation[robotId].y = y;
				robotLocation[robotId].x = x;
				ground[y][x] = robotId;
				break;
			default:
				break;
			}
		}

		// char leftRotation[4] = { 'S', 'E', 'N', 'W' };
		// char rightRotation[4] = { 'S', 'W', 'N', 'E' };
		else if (presentCommand == 'L') {
			int index = repeat;
			switch (robotLocation[robotId].direction)
			{
			case 'S':
				break;
			case 'E':
				index = index + 1;
				break;
			case 'N':
				index = index + 2;
				break;
			case 'W':
				index = index + 3;
				break;
			default:
				break;
			}
			index = index % 4;
			robotLocation[robotId].direction = leftRotation[index];
		}
		else { //command R
			int index = repeat;
			switch (robotLocation[robotId].direction)
			{
			case 'S':
				break;
			case 'W':
				index = index + 1;
				break;
			case 'N':
				index = index + 2;
				break;
			case 'E':
				index = index + 3;
				break;
			default:
				break;
			}
			index = index % 4;
			robotLocation[robotId].direction = rightRotation[index];
		}

	}

	cout << "OK";
	return;
}

int main() {
	Input();
	Answer();
}