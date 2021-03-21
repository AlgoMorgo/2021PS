#include <iostream>

using namespace std;

int N, T;
int time[101], score[101];  // 각 단원별 예상 시간, 배점
int dp[101][10001];         // 첫번째 ~ i 번째 과목까지 봤을때, 가용한 공부시간이 j 일때, 얻을 수 있는 최대 점수

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> T;
    for (int i = 1; i <= N; ++i) cin >> time[i] >> score[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (j - time[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + score[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][T];

    return 0;
}