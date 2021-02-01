/*
    BOJ 17136 색종이 붙이기
    https://www.acmicpc.net/problem/17136
*/

#include <iostream>

#define INF 987654321

using namespace std;

int answer = INF;
int papers[5] = {5, 5, 5, 5, 5};
int adj[10][10];

bool can_cover_paper(int r, int c, int k) {
    for (int i = r; i <= r + k; ++i)
        for (int j = c; j <= c + k; ++j)
            if (i < 0 || i >= 10 || j < 0 || j >= 10 || adj[i][j] == 0)
                return false;
    return true;
}

void attach_paper(int r, int c, int k, bool can_cover) {
    for (int i = r; i <= r + k; ++i)
        for (int j = c; j <= c + k; ++j)
            adj[i][j] = can_cover;
}

void recursion(int r, int c, int cnt) {  // y, x, 붙인갯수
    if (r >= 9 && c > 9) {
        answer = min(answer, cnt);
        return;
    }

    if (answer <= cnt) return;

    if (c > 9) {
        recursion(r + 1, 0, cnt);
        return;
    }

    if (adj[r][c] == 1) {
        for (int k = 4; k >= 0; --k) {
            if (papers[k] > 0 && can_cover_paper(r, c, k)) {
                attach_paper(r, c, k, 0);
                papers[k]--;
                recursion(r, c + 1, cnt + 1);
                attach_paper(r, c, k, 1);
                papers[k]++;
            }
        }
    } else {
        recursion(r, c + 1, cnt);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> adj[i][j];

    recursion(0, 0, 0);

    if (answer == INF) answer = -1;
    cout << answer;

    return 0;
}