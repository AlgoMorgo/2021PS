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

// ������ 1�� ������ �����̰� ��� �ٿ��� ������ true �ƴϸ� false
bool all_visited() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) return false;
		}
	}
	return true;
}

// cũ���� �����̸� ���� �� �ִ��� Ȯ�� �� ���� �� ������ false
// ������ visited�迭�� ������ �� true ��ȯ
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

// cũ���� �����̸� (x,y) -> (x+c, y+c)���� ������ ���� ������ ����
void unDraw(int x, int y, int c) {
	for (int i = y; i < y + c; i++) {
		for (int j = x; j < x + c; j++) {
			visited[i][j] = false;
		}
	}
}
// (0,0) -> (9,9)���� ��ȸ�ϸ� �����̸� �ϳ��� �ٿ�����
void dfs(int x, int y) {
	// ��ȸ�� �������� ���� ����
	if (y == 10) {
		if (all_visited()) {
			int cnt = 0;
			for (int i = 0; i < 5; i++) cnt += 5 - square[i];
			ans = min(ans, cnt);
		}
		return;
	}
	// �����̸� ���� ������ �ƴϰų� �̹� �ٿ��� ������ ���� ��ǥ�� �̵�
	if (arr[y][x] == 0 || visited[y][x]) { 
		if (x != 9) dfs(x + 1, y);
		else dfs(0, y + 1);
		return;
	}
	// 1~5ũ���� �����̸� ���� �� �ִٰ� �ǴܵǸ� ���̰� ���� ��ǥ�� �̵�
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

	// ������ 1�� �κ��� �� ä��� ������ -1 �ƴϸ� ���� ���
	if (ans == 101) cout << -1;
	else cout << ans;

	return 0;
}