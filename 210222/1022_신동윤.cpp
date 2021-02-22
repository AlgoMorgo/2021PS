#include <bits/stdc++.h>

using namespace std;

int r1, c1, r2, c2;
int adj[50][5];

void solve() {
    int max_num = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2)));  // 주어진 좌표에서 그릴 수 있는 소용돌이의 최대갯수를 찾는것.
    int val = 1;                                                      // 배열에 붙일 값

    // 시작 지점 (1을 붙이는곳)
    if (r1 <= 0 && r2 >= 0 && c1 <= 0 && c2 >= 0) adj[0 - r1][0 - c1] = val;

    int cnt = 0;       // 카운팅
    int y = 0, x = 0;  // 좌표

    for (int i = 1; i <= max_num + 1; ++i) {  // 소용돌이의 총 갯수가 max_num + 1 임
        for (int j = 1; j <= 1 + cnt * 2; ++j) {
            val++;
            x++;  // 오른쪽으로 이동
            // 입력으로 주어진 범위 내에 있을때만 값을 부여함.
            if (r1 <= y && r2 >= y && c1 <= x && c2 >= x) adj[y - r1][x - c1] = val;
        }

        for (int j = 1; j <= 1 + cnt * 2; ++j) {
            val++;
            y--;  // 위로 이동
            if (r1 <= y && r2 >= y && c1 <= x && c2 >= x) adj[y - r1][x - c1] = val;
        }

        for (int j = 1; j <= 2 + cnt * 2; ++j) {
            val++;
            x--;  // 왼쪽으로 이동
            if (r1 <= y && r2 >= y && c1 <= x && c2 >= x) adj[y - r1][x - c1] = val;
        }

        for (int j = 1; j <= 2 + cnt * 2; ++j) {
            val++;
            y++;  // 아래로 이동
            if (r1 <= y && r2 >= y && c1 <= x && c2 >= x) adj[y - r1][x - c1] = val;
        }

        cnt++;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> r1 >> c1 >> r2 >> c2;

    solve();

    int H = abs(r2 - r1), W = abs(c2 - c1);  // 높이, 너비

    int max_num = 0;  // 맵에 쓰여진 최대값

    for (int i = 0; i <= H; ++i)
        for (int j = 0; j <= W; ++j)
            max_num = max(max_num, adj[i][j]);

    int max_degree = 0;  // 최대값의 자릿수를 저장
    for (int i = 1; i <= max_num; i *= 10) max_degree++;

    // 자릿수를 맞추는 이유는 출력시에 일정하게 출력하기 위해서이다.
    for (int i = 0; i <= H; ++i) {
        for (int j = 0; j <= W; ++j) {
            int current_degree = 0;
            for (int k = 1; k <= adj[i][j]; k *= 10) current_degree++;
            for (int k = current_degree; k < max_degree; ++k) cout << " ";

            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}