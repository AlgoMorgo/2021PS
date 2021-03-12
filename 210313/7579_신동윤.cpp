#include <iostream>

using namespace std;

int N, M;                 // 활성화된 앱 갯수, 확보해야할 메모리
pair<int, int> app[101];  // 점유 중인 메모리 바이트 m, 비활성 비용 c
int dp[10001];            // 비용이 i 일때, 확보 가능한 메모리
int sum;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> app[i].first;
    for (int i = 1; i <= N; ++i) {
        cin >> app[i].second;
        sum += app[i].second;
    }

    for (int i = 1; i <= N; ++i)
        for (int j = sum; j >= app[i].second; --j)
            dp[j] = max(dp[j], dp[j - app[i].second] + app[i].first);

    int answer = 0;
    while (1) {
        if (answer < sum && dp[answer] < M)
            answer++;
        else
            break;
    }
    cout << answer;

    return 0;
}