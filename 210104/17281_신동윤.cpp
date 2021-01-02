/*
    BOJ 17281 야구
    https://www.acmicpc.net/problem/17281
*/

#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX_INNING 51
#define MAX_HITTER 10

using namespace std;

int N, answer;
int hitters[MAX_INNING][MAX_HITTER];  // hitters[i][j] = k : i번째 이닝에 j번째 선수가 낼 수 있는 점수가 k
int order[MAX_HITTER];                // 타순, order[i] = j : i번째 타자는 j번 선수
int ru[4];                            // 타석, 1루, 2루, 3루 순서
bool selected[MAX_HITTER];            // 순열을 위한 변수

void game() {
    int score = 0, start = 1;
    for (int i = 1; i <= N; ++i) {  // i 는 이닝번호
        int out_num = 0;
        bool flag = false;
        memset(ru, 0, sizeof(ru));
        while (1) {
            for (int j = start; j < MAX_HITTER; ++j) {  // j 는 선수 번호
                int hitter = hitters[i][order[j]];      // i번째 이닝에, j번째 선수가 낼 수 있는 점수
                if (hitter == 0)
                    out_num++;           // 아웃일때
                else if (hitter == 4) {  // 홈런일때
                    for (int k = 1; k <= 3; ++k) {
                        if (ru[k]) {
                            ru[k] = 0;  // 홈런일때는 모든 루를 비우고 점수를 1증가
                            score++;
                        }
                    }
                    score++;
                } else {  // 안타, 2루타, 3루타 일때
                    for (int k = 3; k >= 1; --k) {
                        if (ru[k]) {  // 3루 부터 각 숫자에 맞는 칸만큼 앞으로 당김
                            if (k + hitter > 3) {
                                ru[k] = 0;
                                score++;
                            } else {
                                ru[k + hitter] = 1;
                                ru[k] = 0;
                            }
                        }
                    }
                    ru[hitter] = 1;
                }
                if (out_num == 3) {  // 아웃3번시 다음 이닝으로
                    start = j + 1;
                    if (start == MAX_HITTER) start = 1;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            start = 1;
        }
    }
    answer = max(answer, score);
}

void recursion(int idx) {  // 순열 구현을 위한 재귀함수
    if (idx == MAX_HITTER) {
        game();
        return;
    }

    for (int i = 1; i < MAX_HITTER; ++i) {
        if (selected[i]) continue;
        selected[i] = true;
        order[i] = idx;
        recursion(idx + 1);
        selected[i] = false;
    }
}

void solve() {
    // 4번 타자가 항상 1번 선수여야하므로
    selected[4] = true;
    order[4] = 1;
    recursion(2);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j < MAX_HITTER; ++j)
            cin >> hitters[i][j];

    solve();

    cout << answer;

    return 0;
}