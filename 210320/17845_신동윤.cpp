#include <algorithm>
#include <iostream>

using namespace std;

int N, K;
int importance[1001], time[1001];  // 중요도, 시간
int dp[1001][10001];               // dp[i][j] : 0 ~ i번째 과목 까지 살피면서, 가용한 시간이 j 일때, 최대 중요도

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 1; i <= K; ++i)
        cin >> importance[i] >> time[i];

    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (j - time[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + importance[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[K][N];

    return 0;
}