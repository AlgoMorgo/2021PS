/*
풀이 : 그냥 시뮬
좌표 설정 조심
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
int Map[101][101];
map<char, int>m;
struct info
{
	int x, y, dir;
};
vector<info> robots(101);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int A, B, N, M;
	cin >> A >> B >> N >> M;
	m['E'] = 0; m['S'] = 1; m['W'] = 2; m['N'] = 3;

	for (int i = 1; i <= N; i++) { // 입력
		int x, y;
		char d;
		cin >> x >> y >> d;
		robots[i] = { x,y,m[d] };
		Map[y][x] = i;
	}

	while (M--) {
		int num, cnt;
		char command;
		cin >> num >> command >> cnt;

		int d = robots[num].dir;

		if (command == 'F') { // cnt 만큼 전진
			while (cnt--) {
				int nx = robots[num].x + dx[d];
				int ny = robots[num].y + dy[d];

				if (nx <= 0 || ny <= 0 || nx > A || ny > B) { // 맵을 벗어날 때
					printf("Robot %d crashes into the wall", num);
					return 0;
				}
				else if (Map[ny][nx]) { // 다른 로봇과 충돌
					printf("Robot %d crashes into robot %d", num, Map[ny][nx]);
					return 0;
				}
				Map[robots[num].y][robots[num].x] = 0;
				Map[ny][nx] = num;
				robots[num].y = ny;
				robots[num].x = nx; // 좌표 갱신
			}
		}
		else if (command == 'L') robots[num].dir = (robots[num].dir + 3 * cnt) % 4;
		else if (command == 'R') robots[num].dir = (robots[num].dir + cnt) % 4; 
	}
	cout << "OK";
	return 0;
}