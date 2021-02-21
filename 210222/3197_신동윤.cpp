#include <bits/stdc++.h>

#define MAX 1500

using namespace std;

int R, C, answer;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
string adj[MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> swan;           // 백조 좌표
queue<pair<int, int>> water_queue, q;  // 물 좌표, BFS 탐색큐
bool flag;                             // 탐색 도중 두 백조가 만나는 경우

void swan_bfs() {
    queue<pair<int, int>> next_queue;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == swan[1].first && x == swan[1].second) {
            flag = true;  // 두 백조가 만남
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;

            visited[ny][nx] = true;

            if (adj[ny][nx] == 'X') {
                next_queue.push({ny, nx});
                continue;
            }

            q.push({ny, nx});
        }
    }

    q = next_queue;
}

void water_bfs() {
    int size = water_queue.size();
    while (size--) {
        int y = water_queue.front().first;
        int x = water_queue.front().second;
        water_queue.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

            if (adj[ny][nx] == 'X') {
                adj[ny][nx] = '.';
                water_queue.push({ny, nx});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> adj[i];
        for (int j = 0; j < C; ++j) {
            if (adj[i][j] == 'L') swan.push_back({i, j});
            if (adj[i][j] == '.' || adj[i][j] == 'L') water_queue.push({i, j});
        }
    }

    q.push(swan[0]);

    visited[swan[0].first][swan[0].second] = true;

    while (1) {
        swan_bfs();

        if (flag) break;  // 도중에 두 백조가 만난 경우

        water_bfs();

        answer++;
    }

    cout << answer;

    return 0;
}
