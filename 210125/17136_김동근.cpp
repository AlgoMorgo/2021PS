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

int arr[10][10];
int square[5] = { 5,5,5,5,5 };
bool visited[10][10];
int ans = 101;

// 종이의 1인 구역에 색종이가 모두 붙여져 있으면 true 아니면 false
bool all_visited() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) return false;
		}
	}
	return true;
}

// c크기의 색종이를 붙일 수 있는지 확인 후 붙일 수 없으면 false
// 있으면 visited배열을 갱신한 후 true 반환
bool draw(int x, int y, int c) {
	for (int i = y; i < y + c; i++) {
		for (int j = x; j < x + c; j++) {
			if (i >= 10 || j >= 10 || arr[i][j] == 0 || visited[i][j] == true) 
				return false;
		}
	}
	for (int i = y; i < y + c; i++) {
		for (int j = x; j < x + c; j++) {
			visited[i][j] = true;
		}
	}
	return true;
}

// c크기의 색종이를 (x,y) -> (x+c, y+c)까지 붙이지 않은 것으로 갱신
void unDraw(int x, int y, int c) {
	for (int i = y; i < y + c; i++) {
		for (int j = x; j < x + c; j++) {
			visited[i][j] = false;
		}
	}
}
// (0,0) -> (9,9)까지 순회하면 색종이를 하나씩 붙여본다
void dfs(int x, int y) {
	// 순회가 끝났으면 정답 갱신
	if (y == 10) {
		if (all_visited()) {
			int cnt = 0;
			for (int i = 0; i < 5; i++) cnt += 5 - square[i];
			ans = min(ans, cnt);
		}
		return;
	}
	// 색종이를 붙일 구역이 아니거나 이미 붙여져 있으면 다음 좌표로 이동
	if (arr[y][x] == 0 || visited[y][x]) { 
		if (x != 9) dfs(x + 1, y);
		else dfs(0, y + 1);
		return;
	}
	// 1~5크기의 색종이를 붙일 수 있다고 판단되면 붙이고 다음 좌표로 이동
	for (int i = 0; i < 5; i++) {
		if (square[i] && draw(x, y, i + 1)) {
			square[i]--;
			if (x != 9) dfs(x + 1, y);
			else dfs(0, y + 1);
			square[i]++;
			unDraw(x, y, i + 1);
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0);

	// 종이의 1인 부분을 다 채울수 없으면 -1 아니면 정답 출력
	if (ans == 101) cout << -1;
	else cout << ans;

	return 0;
}