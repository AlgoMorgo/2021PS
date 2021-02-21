#include <bits/stdc++.h>

#define MAX 300001

using namespace std;

int N, S;                 // 그림 갯수, 판매 가능한 세로 길이
int dp[MAX];              // dp[n] : 1 ~ n 번째 그림 비교시에 판매 가능한 그림의 최대값
int temp[MAX];            // temp[n] : n 번째 그림을 전시했을때 그 보다 앞에 전시한것중 가장 높은 그림
pair<int, int> arr[MAX];  // 높이, 가격

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> S;

    for (int i = 1; i <= N; ++i)
        cin >> arr[i].first >> arr[i].second;

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; ++i) {
        temp[i] = temp[i - 1] + 1;
        while (temp[i] < i) {
            if (arr[i].first - arr[temp[i]].first < S) break;
            temp[i]++;
        }
        temp[i]--;
    }

    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[temp[i]] + arr[i].second;
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[N];

    return 0;
}
