#include <iostream>

#define MAX 1502

using namespace std;

int R, C;
int apple[MAX][MAX], banana[MAX][MAX], dp[MAX][MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C;

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            char ch;
            int num;

            cin >> ch >> num;

            if (ch == 'A')
                apple[i][j] = num;
            else if (ch == 'B')
                banana[i][j] = num;
        }
    }

    // 전처리 (우측 누적합 계산)
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            apple[i][j] += apple[i][j - 1];
            banana[i][j] += banana[i][j - 1];
        }
    }

    // 전처리 (아래 누적합 계산)
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            apple[i][j] += apple[i - 1][j];
            banana[i][j] += banana[i - 1][j];
        }
    }

    // 전처리 (1행 초기화)
    for (int j = 1; j <= C; ++j) dp[1][j] = apple[R][j] - apple[1][j];

    // 전처리 (1열 초기화)
    for (int i = 1; i <= R; ++i) dp[i][1] = apple[R][1] - apple[i][1];

    for (int i = 2; i <= R; ++i) {
        for (int j = 2; j <= C; ++j) {
            // 오른쪽
            dp[i][j] = max(dp[i][j],
                           dp[i][j - 1] + apple[R][j] - apple[R][j - 1] - apple[i][j] + apple[i][j - 1] + banana[i - 1][j] - banana[i - 1][j - 1]);

            // 아래
            dp[i][j] = max(dp[i][j],
                           dp[i - 1][j] - (apple[i][j] - apple[i][j - 1] - apple[i - 1][j] + apple[i - 1][j - 1]));

            // 대각선 오른쪽 아래
            dp[i][j] = max(dp[i][j],
                           dp[i - 1][j - 1] + apple[R][j] - apple[R][j - 1] - apple[i][j] + apple[i][j - 1] + banana[i - 1][j] - banana[i - 1][j - 1]);
        }
    }

    cout << dp[R][C];

    return 0;
}