#include <cstring>
#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int N, answer1, answer2;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char adj[MAX][MAX];
bool visited[MAX][MAX];

void bfs1(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        char ch = adj[y][x];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];

            if (visited[ny][nx] || ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (adj[ny][nx] == ch) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void bfs2(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        char ch = adj[y][x];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];

            if (visited[ny][nx] || ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            if (ch == 'R' || ch == 'G') {
                if (adj[ny][nx] == 'R' || adj[ny][nx] == 'G') {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            } else {
                if (adj[ny][nx] == ch) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> adj[i][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                bfs1(i, j);
                answer1++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                bfs2(i, j);
                answer2++;
            }
        }
    }

    cout << answer1 << " " << answer2;

    return 0;
}