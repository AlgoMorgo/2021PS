/*
    BOJ 2933 미네랄
    https://www.acmicpc.net/problem/2933
*/

#include <bits/stdc++.h>

#define MAX 101
#define INF 987654321

using namespace std;

int R, C, N;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char adj[MAX][MAX];
bool visited[MAX][MAX], air[MAX][MAX];  // 공중에 떠있는 미네랄 체크를 위한 변수
vector<int> sticks;                     // 던진 막대의 높이
vector<pair<int, int>> air_pos;         // 공중에 떠있는 미네랄 좌표 체크

int dist(int y, int x) {
    // 클러스터를 몇칸 내려야 하는지 파악하는 함수

    int cnt = 0;
    for (int i = y + 1; i < R; ++i) {
        if (adj[i][x] == 'x') {
            if (air[i][x])
                return INF;
            else
                return cnt;
        } else if (adj[i][x] == '.') {
            cnt++;
        }
    }

    return cnt;
}

void update_map() {
    // 공중에 떠있는 클러스터를 밑으로 내리는 함수

    int height = INF - 1;
    for (int i = 0; i < air_pos.size(); ++i) {
        int y = air_pos[i].first, x = air_pos[i].second;

        int temp = dist(y, x);

        if (temp == INF)
            continue;
        else
            height = min(height, temp);
    }

    sort(air_pos.begin(), air_pos.end());

    for (int i = air_pos.size() - 1; i >= 0; --i) {
        int y = air_pos[i].first, x = air_pos[i].second;

        adj[y][x] = '.';
        adj[y + height][x] = 'x';
    }
}

bool throw_stick(int row, char ch) {
    // 스틱을 던지기 위한 함수

    if (ch == 'L') {
        // 왼쪽에서 던짐
        for (int i = 0; i < C; ++i) {
            if (adj[row][i] == 'x') {
                adj[row][i] = '.';
                return true;
            }
        }
    } else {
        // 오른쪽에서 던짐
        for (int i = C - 1; i >= 0; --i) {
            if (adj[row][i] == 'x') {
                adj[row][i] = '.';
                return true;
            }
        }
    }

    return false;
}

void bfs(int i, int j) {
    // 미네랄 탐색을 위한 bfs
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

            if (adj[ny][nx] == 'x' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

bool is_air() {
    // 공중에 떠있는 클러스터 확인을 위한 함수

    // 밑바닥 부터 확인
    for (int i = 0; i < C; ++i)
        if (adj[R - 1][i] == 'x' && !visited[R - 1][i])
            bfs(R - 1, i);

    bool temp = false;

    memset(air, false, sizeof(air));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (adj[i][j] == 'x' && !visited[i][j]) {
                temp = true;
                air_pos.push_back({i, j});
                air[i][j] = true;
            }
        }
    }

    return temp;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> adj[i][j];
        }
    }

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        sticks.push_back(num);
    }

    for (int i = 0; i < sticks.size(); ++i) {
        air_pos.clear();
        memset(visited, false, sizeof(visited));
        memset(air, false, sizeof(air));

        char turn;  // 짝홀에 따른 순서 부여
        int height = sticks[i];
        height = R - height;

        if (i % 2 == 0)
            turn = 'L';
        else
            turn = 'R';

        if (!throw_stick(height, turn)) continue;  // 던졌는데 미네랄 안나옴

        if (!is_air())
            continue;  // 공중에 떠있는 미네랄 없음
        else
            update_map();  // 공중에 떠있는 미네랄 있으므로 맵 수정
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << adj[i][j];
        }
        cout << "\n";
    }

    return 0;
}