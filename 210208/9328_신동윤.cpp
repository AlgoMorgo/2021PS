/*
    BOJ 9328 열쇠
    https://www.acmicpc.net/problem/9328
*/

#include <bits/stdc++.h>

#define MAX 102

using namespace std;

int T, answer, H, W;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char adj[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 범위 벗어난 경우
        if (y < 0 || y > H + 1 || x < 0 || x > W + 1) continue;

        // 이미 갔던곳, 벽, 막힌 문
        if (visited[y][x] || adj[y][x] == '*' || ('A' <= adj[y][x] && adj[y][x] <= 'Z')) continue;

        visited[y][x] = true;

        // 문서 발견
        if (adj[y][x] == '$') {
            answer++;
            adj[y][x] = '.';
        }

        // 열쇠 발견, 미리 문 다 따고 다시 시작
        if ('a' <= adj[y][x] && adj[y][x] <= 'z') {
            char door = (char)toupper(adj[y][x]);
            adj[y][x] = '.';

            for (int i = 1; i <= H; ++i)
                for (int j = 1; j <= W; ++j)
                    if (adj[i][j] == door)
                        adj[i][j] = '.';

            memset(visited, false, sizeof(visited));

            while (!q.empty())
                q.pop();

            q.push({y, x});
            continue;
        }

        // bfs 다음 탐색
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            q.push({ny, nx});
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while (T--) {
        memset(adj, '.', sizeof(adj));
        memset(visited, false, sizeof(visited));
        answer = 0;

        cin >> H >> W;

        for (int i = 1; i <= H; ++i)
            for (int j = 1; j <= W; ++j)
                cin >> adj[i][j];

        string temp;
        cin >> temp;
        if (temp != "0") {
            for (int k = 0; k < temp.length(); ++k) {
                for (int i = 1; i <= H; ++i)  // 미리 문 따놓고 시작
                    for (int j = 1; j <= W; ++j)
                        if (adj[i][j] == (char)toupper(temp[k]))
                            adj[i][j] = '.';
            }
        }

        bfs(0, 0);

        cout << answer << "\n";
    }

    return 0;
}