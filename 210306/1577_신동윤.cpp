#include <iostream>

using namespace std;

int N, M, K;             // 가로, 세로, 공사
bool visited[201][201];  // 공사 지역 방문처리
long long dp[101][101];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int a, b, c, d;  // (a, b) , (c, d)
        cin >> a >> b >> c >> d;
        visited[b + d][a + c] = true;  // y, x 순
    }

    dp[0][0] = 1;  // 시작 지점으로 가는 경우의 수 1개

    for (int i = 1; i <= M; ++i) {
        if (visited[2 * i - 1][0]) break;
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[0][2 * i - 1]) break;
        dp[0][i] = 1;
    }

    // O(NM) 가능
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!visited[2 * i - 1][2 * j])
                dp[i][j] += dp[i - 1][j];

            if (!visited[2 * i][2 * j - 1])
                dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[M][N];

    return 0;
}