/*
    BOJ 15997 승부 예측
    https://www.acmicpc.net/problem/15997
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Game {
    int A, B;
    double W, D, L;
};

map<string, int> nations;  // 국가 이름, 인덱스번호

Game game_list[6];
int score[6];
double probability[6];
pair<int, int> temp_score[4];  // 점수, 국가 번호

void play(int idx, double prob) {  // 경기 횟수, 확률
    if (idx == 6) {
        // 6번의 경기를 치름
        if (prob == 0) return;
        for (int i = 0; i < 4; ++i)
            temp_score[i] = {score[i], i};

        sort(temp_score, temp_score + 4);

        int a_score = temp_score[0].first;
        int b_score = temp_score[1].first;
        int c_score = temp_score[2].first;
        int d_score = temp_score[3].first;

        int a_idx = temp_score[0].second;
        int b_idx = temp_score[1].second;
        int c_idx = temp_score[2].second;
        int d_idx = temp_score[3].second;

        if (b_score != c_score) {  // 상위 2개 국가 진출
            probability[c_idx] += prob;
            probability[d_idx] += prob;
        } else if (a_score == b_score && c_score == d_score) {  // 4개 국가 점수 모두 동일
            probability[a_idx] += prob / 2;
            probability[b_idx] += prob / 2;
            probability[c_idx] += prob / 2;
            probability[d_idx] += prob / 2;
        } else if (a_score == b_score) {  // 하위 3개 국가 점수 동일
            probability[a_idx] += prob / 3;
            probability[b_idx] += prob / 3;
            probability[c_idx] += prob / 3;
            probability[d_idx] += prob;
        } else if (c_score == d_score) {  // 상위 3개 국가 점수 동일
            probability[b_idx] += prob * 2 / 3;
            probability[c_idx] += prob * 2 / 3;
            probability[d_idx] += prob * 2 / 3;
        } else {  // 최상위 d 국가 진출, 두번째 랭크 b, c 국가 점수 동일
            probability[b_idx] += prob / 2;
            probability[c_idx] += prob / 2;
            probability[d_idx] += prob;
        }

        return;
    }

    // 한번의 경기를 치를때 마다 누가 이겼는지 스코어 계산해야됨.
    Game temp = game_list[idx];  // idx 번째의 게임 정보

    // A 국가의 승리
    score[temp.A] += 3;
    play(idx + 1, prob * temp.W);
    score[temp.A] -= 3;  // backtracking

    // 비긴경우
    score[temp.A] += 1;
    score[temp.B] += 1;
    play(idx + 1, prob * temp.D);
    score[temp.A] -= 1;
    score[temp.B] -= 1;

    // B 국가의 승리
    score[temp.B] += 3;
    play(idx + 1, prob * temp.L);
    score[temp.B] -= 3;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 4; ++i) {
        string nation;
        cin >> nation;
        nations[nation] = i;
    }

    for (int i = 0; i < 6; ++i) {
        string A, B;
        double W, D, L;
        cin >> A >> B >> W >> D >> L;
        game_list[i] = {nations[A], nations[B], W, D, L};
    }

    play(0, 1.0);

    cout << fixed;
    cout.precision(10);
    for (int i = 0; i < 4; ++i)
        cout << probability[i] << "\n";

    return 0;
}