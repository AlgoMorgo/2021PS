#include <bits/stdc++.h>

#define MAX_N 101
#define MAX_M 51
#define MIN -3276800

using namespace std;

int N, M;
int arr[MAX_N];
int dp[MAX_N][MAX_M];  // dp[n][m] : 1 ~ n 인덱스까지 1차원 배열에서 m 개의 구간 선택시 합의 최대

int solve(int n, int m) {
    // base case
    if (m == 0) return 0;    // 구간을 하나도 선택하지 않을때
    if (n <= 0) return MIN;  // 에러처리
    if (dp[n][m] != -1) return dp[n][m];

    int sum = 0;
    dp[n][m] = solve(n - 1, m);  // n 번째를 제외한 이전 구간들의 경우의 수 계산 (재귀함수)
    for (int i = n; i > 0; --i) {
        sum += arr[i];                         // i ~ n 의 구간합
        int temp = solve(i - 2, m - 1) + sum;  // 인접하지 않는 범위에서, m - 1 개의 구간합의 최댓값 구함
        dp[n][m] = max(dp[n][m], temp);
    }

    return dp[n][m];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(N, M);

    return 0;
}