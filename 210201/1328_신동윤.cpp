/*
    BOJ 1328 고층 빌딩
    https://www.acmicpc.net/problem/1328
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int N, L, R;
// dp[i][j][k] = w : 건물이 i 개 이고, 왼쪽과 오른쪽에서 각각 j, k 개가 보이는 경우 가능한 총 경우의 수가 w.
int dp[101][101][101];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> L >> R;
    dp[1][1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= L; ++j) {
            for (int k = 1; k <= R; ++k) {
                dp[i][j][k] = ((long long)dp[i - 1][j][k] * (i - 2) + dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k]) % MOD;
            }
        }
    }

    cout << dp[N][L][R];

    return 0;
}
