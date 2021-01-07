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

const int dx[3] = { -1,0,1 };
const int dy[4] = { 0,-1,0 };

using namespace std;

int N, M, D;
// 적 개수
int cnt = 0;
// 이동시킬 맵
int arr[16][16];
// 원본 맵
int Arr[16][16];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Arr[i][j];
			if (Arr[i][j]) {
				cnt++; // 적 카운트
			}
		}
	}

	vector<int> permutation(M - 3, 0); // 순열에 필요한 배열
	permutation.push_back(1); permutation.push_back(1); permutation.push_back(1);

	int ans = 0;
	do {
		int archer[3], index = 0;
		for (int i = 0; i < M; i++)
			if (permutation[i] == 1) archer[index++] = i; // 궁수 자리 지정

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) arr[i][j] = Arr[i][j]; // 맵 복사

		int count = cnt; // 적 개수
		int sum = 0; // 
		while (count > 0) {
			bool kill[16][16] = { false };
			for (int k = 0; k < 3; k++) {

				bool visited[16][16] = { false }; // 방문체크
				queue<pair<int, pair<int, int>>> q; // <거리, <y, x>>
				q.push({ 0,{ N, archer[k] } });
				int tx = -1, ty = -1, len = M + 1;
				while (!q.empty()) {
					int x = q.front().second.second;
					int y = q.front().second.first;
					int cost = q.front().first;
					q.pop();

					if (cost > D || visited[y][x]) continue; // 거리넘어가거나 방문했을 때
					visited[y][x] = true;

					if (arr[y][x] == 1) { // 적일 때
						tx = x;
						ty = y;
						break;
					}
					for (int i = 0; i < 3; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

						q.push({ cost + 1, {ny, nx} });
					}
				}
				if (tx != -1 && !kill[ty][tx]) { // 아직 안죽은 적일때
					kill[ty][tx] = true;
					count--;
					sum++;
				}
				if (count <= 0) break;
			}
			for (int i = 0; i < N; i++) // 죽은 적 갱신
				for (int j = 0; j < M; j++)
					if (kill[i][j]) arr[i][j] = 0;

			for (int i = 0; i < M; i++) { // 맵을 벗어나는 적 카운트
				if (arr[N - 1][i] == 1) {
					count--;
				}
			}

			for (int i = N - 1; i > 0; i--) { // 맵 이동
				for (int j = 0; j < M; j++) {
					arr[i][j] = arr[i - 1][j];
					arr[i - 1][j] = 0;
				}
			}
		}
		ans = max(ans, sum);
	} while (next_permutation(permutation.begin(), permutation.end()));

	cout << ans;

	return 0;
}