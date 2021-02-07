/*
    BOJ 1043 거짓말
    https://www.acmicpc.net/problem/1043
*/

#include <bits/stdc++.h>

#define MAX 51

using namespace std;

int N, M;                   // 참석자, 파티 수
bool known[MAX];            // 진실을 아는 사람 목록
bool arr[MAX][MAX];         // i 번째 파티 j 번 참가자
bool all_known_party[MAX];  // 파티의 모든 참가자가 진실을 아는지 체크

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    int num_of_known;
    cin >> num_of_known;
    for (int i = 1; i <= num_of_known; ++i) {
        int temp;
        cin >> temp;
        known[temp] = true;
    }

    for (int i = 1; i <= M; ++i) {
        int num_of_party_members;
        cin >> num_of_party_members;

        for (int j = 1; j <= num_of_party_members; ++j) {
            int temp;
            cin >> temp;
            arr[i][temp] = true;
        }
    }

    bool flag;
    while (true) {
        flag = false;

        for (int i = 1; i <= M; ++i) {
            // i번째 파티의 참가자들이 모두 진실을 알때
            if (all_known_party[i]) continue;

            bool is_someone_known = false;
            for (int j = 1; j <= N; ++j) {
                if (arr[i][j] && known[j]) {
                    is_someone_known = true;
                    break;
                }
            }

            // 한명이라도 아는경우
            if (is_someone_known) {
                for (int j = 1; j <= N; ++j) {
                    if (arr[i][j] && !known[j]) {
                        known[j] = true;
                        flag = true;
                    }
                }
                all_known_party[i] = true;
            }
        }

        if (!flag) break;
    }

    int answer = 0;
    for (int i = 1; i <= M; ++i)
        if (!all_known_party[i])
            answer++;

    cout << answer;

    return 0;
}