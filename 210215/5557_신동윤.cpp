#include <bits/stdc++.h>

#define MAX 101

using namespace std;

int N;
int arr[MAX];
long long dp[MAX][21];  // dp[i][j] = k : i 번째 위치에 있는 숫자 j (0 ~ 20) 가 나올때 경우의 수 k

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];

    dp[1][arr[1]] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if (dp[i - 1][j] != 0) {                                      // 이전 경우의 수가 존재하는 경우
                if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];   // 이전수와의 차가 양수일때
                if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];  // 이전수와의 합산이 20 이하일때
            }
        }
    }

    cout << dp[N - 1][arr[N]];

    return 0;
}