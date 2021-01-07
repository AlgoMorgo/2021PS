/*  
    BOJ 17135 캐슬 디펜스
    https://www.acmicpc.net/problem/17135
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX 15

using namespace std;

typedef struct {
    int y;
    int x;
    int distance;
} EnemyInfo;

int N, M, D, answer, score;
int map[MAX][MAX], copied_map[MAX][MAX];
bool selected[MAX];                         // 조합 구현을 위한 변수
bool visited[MAX][MAX];                     // 궁수가 동시에 쏜 적을 중복해서 카운팅하는것을 방지하기 위한 변수
vector<pair<int, int>> living_enemies_pos;  // 적좌표기록
vector<int> archers_col;                    // 궁수가 몇번째 열에 위치해있는지 파악하기 위한 벡터

int cal(int r, int c, int y, int x) {  // 거리계산
    return abs(r - y) + abs(c - x);
}

bool all_dead() {
    bool flag = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (copied_map[i][j] == 1) {  // 살아 있는적 있을때
                flag = false;
                living_enemies_pos.push_back({i, j});
            }
        }
    }
    return flag;
}

void copy_map() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            copied_map[i][j] = map[i][j];
}

bool comp(EnemyInfo enemy1, EnemyInfo enemy2) {
    if (enemy1.distance <= enemy2.distance) {      // 거리가 가까운게 앞으로 오름차순
        if (enemy1.distance == enemy2.distance) {  // 거리가 같은경우 왼쪽에 있는지 아닌지 따져야됨
            if (enemy1.x < enemy2.x) {             // 거리도 가까운게 여럿일때 왼쪽에 있는게 우선
                return true;                       // 거리가 가까우면서 왼쪽에 있을때 앞으로옴
            }
            return false;  // 거리는 같지만 왼쪽에 있지 않은경우
        }
        return true;  // 거리는 서로 다르지만 한쪽이 더 가까이 있는 경우
    }
    return false;  // 위조건 모두 아닌경우
}

void move_down_enemy() {
    for (int i = living_enemies_pos.size() - 1; i >= 0; --i) {
        int y = living_enemies_pos[i].first;
        int x = living_enemies_pos[i].second;

        if (!copied_map[y][x]) continue;  // 적이 없는 위치면 넘김

        if (y == N - 1)
            copied_map[y][x] = 0;  // 마지막행은 0 처리 (N번째 행은 궁수의 자리여서 아래부분 처리 안함)
        else {
            copied_map[y][x] = 0;
            copied_map[y + 1][x] = 1;  // 적을 아래 행으로 옮김
        }
    }
}

void remove_enemy() {
    pair<int, int> archers_targets[3];  // 궁수가 동시에 화살을 쏘기 위해 타겟의 좌표를 담는 변수, 동시에 같은적을 쏘는것을 구현하기 위함

    for (int i = 0; i < archers_col.size(); ++i) {  // 궁수가 위치한 열 만큼 순회하여 적거리 계산
        int y = N, x = archers_col[i];              // 궁수의 좌표
        vector<EnemyInfo> temp_enemies_info;        // 궁수가 죽일수 있는 적들의 위치를 담은 벡터
        for (int j = 0; j < living_enemies_pos.size(); ++j) {
            int enemy_y = living_enemies_pos[j].first;
            int enemy_x = living_enemies_pos[j].second;
            int distance = cal(y, x, enemy_y, enemy_x);
            if (distance <= D) {  // 사정거리 내에 있을때
                EnemyInfo temp;
                temp.y = enemy_y;
                temp.x = enemy_x;
                temp.distance = distance;
                temp_enemies_info.push_back(temp);
            }
        }

        int num = temp_enemies_info.size();
        if (num > 1) {  // 궁수가 죽일수 있는 적이 2명 이상일때
            sort(temp_enemies_info.begin(), temp_enemies_info.end(), comp);
            archers_targets[i].first = temp_enemies_info[0].y;  // 0 인덱스인것은 가장 가까운 적을 먼저 처리하기 위함임
            archers_targets[i].second = temp_enemies_info[0].x;
        } else if (num == 1) {  // 1명일때
            archers_targets[i].first = temp_enemies_info[0].y;
            archers_targets[i].second = temp_enemies_info[0].x;
        } else {  // 없을때
            archers_targets[i].first = -1;
            archers_targets[i].second = -1;
        }
    }

    for (int i = 0; i < 3; ++i) {  // 세 궁수가 동시에 공격
        int y = archers_targets[i].first;
        int x = archers_targets[i].second;

        if (y == -1 && x == -1) continue;
        if (!visited[y][x]) {
            visited[y][x] = true;
            copied_map[y][x] = 0;
            score++;
        }
    }
}

void game() {
    copy_map();  // 원본 맵 그대로 적 제거하고 움직이면 조합 구현이 불가능 (다른 경우의 수를 못셈)
    while (1) {
        memset(visited, false, sizeof(visited));
        living_enemies_pos.clear();

        if (all_dead()) break;  // 적이 없으면 게임 끝

        remove_enemy();
        move_down_enemy();
    }
}

void set_archers_pos(int idx, int cnt) {  // 조합 구현을 위한 함수 idx : 궁수 열 위치, cnt : 뽑은 궁수의 숫자
    if (cnt == 3) {                       // 궁수를 3명 뽑았을때 게임 실행
        score = 0;
        game();
        answer = max(answer, score);
        return;
    }

    for (int i = idx; i < M; ++i) {  // 열 크기 만큼 반복
        if (selected[i]) continue;
        selected[i] = true;
        archers_col.push_back(i);
        set_archers_pos(i, cnt + 1);
        archers_col.pop_back();
        selected[i] = false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> D;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    set_archers_pos(0, 0);
    cout << answer;

    return 0;
}