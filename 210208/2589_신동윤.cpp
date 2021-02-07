/*
    BOJ 2589 보물섬
    https://www.acmicpc.net/problem/2589
*/

#include <bits/stdc++.h>

#define MAX 51

using namespace std;

char adj[MAX][MAX];
bool visited[MAX][MAX];
int depth[MAX][MAX];  // 거리 계산을 위한 배열
int L, W, answer;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push({i, j});

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || ny > L || nx < 0 || nx > W) continue;

            if (adj[ny][nx] == 'L' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});

                depth[ny][nx] = depth[y][x] + 1;

                answer = max(answer, depth[ny][nx]);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> L >> W;

    char temp;
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> temp;
            adj[i][j] = temp;
        }
    }

    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (adj[i][j] == 'L') {
                bfs(i, j);
                memset(visited, false, sizeof(visited));
                memset(depth, 0, sizeof(depth));
            }
        }
    }

    cout << answer;

    return 0;
}