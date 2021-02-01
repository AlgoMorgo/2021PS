/*
    BOJ 1941 소문난 칠공주
    https://www.acmicpc.net/problem/1941
*/

#include <bits/stdc++.h>

using namespace std;

int answer;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char adj[5][5];
bool visited[5][5];
bool selected_student[5][5];  // 뽑아낸 7명 중에서, BFS 를 돌리기 위해 인접행렬의 크기와 맞춰주도록 재배열함.
bool selected[25];            // 25 명 중에서 7명을 뽑아내기 위한 변수

bool isAdjacent() {
    queue<pair<int, int>> q;
    bool is_answer = false;

    memset(visited, false, sizeof(visited));
    memset(selected_student, false, sizeof(selected_student));

    // bfs 를 위한 큐에 넣을 최초의 값
    int temp = 0;
    for (int i = 0; i < 25; ++i) {
        if (selected[i]) {
            selected_student[i / 5][i % 5] = true;  // 0 ~ 24 까지 총 25개의 수를 5로 나누면, 행 좌표가되고, 5의 나머지를 구하면 열의 좌표가된다.
            if (!temp) {
                q.push(make_pair(i / 5, i % 5));
                visited[i / 5][i % 5] = true;
                temp++;
            }
        }
    }

    int cnt = 1;  // 1 인 것은 앞선 코드에서 1개를 잡아놨기 때문
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (cnt == 7) {
            is_answer = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if (selected_student[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                cnt++;
            }
        }
    }

    if (is_answer) return true;
    return false;
}

bool count_member() {
    int lee = 0;
    for (int i = 0; i < 25; ++i) {
        if (!selected[i]) continue;
        if (adj[i / 5][i % 5] == 'S') lee++;
    }
    if (lee >= 4) return true;
    return false;
}

void combination(int idx, int depth) {
    if (depth == 7) {
        if (count_member()) {
            if (isAdjacent()) {
                answer++;
            }
        }
        return;
    }

    for (int i = idx; i < 25; ++i) {
        if (selected[i]) continue;
        selected[i] = true;

        combination(i, depth + 1);
        selected[i] = false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> adj[i][j];

    combination(0, 0);

    cout << answer;

    return 0;
}
