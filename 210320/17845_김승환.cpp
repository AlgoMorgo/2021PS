#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> dp(N+1);
    for (int i=0; i<K; ++i)
    {
        int I, T;
        cin >> I >> T;
        for (int j=N-T; j>=0; --j)
            dp[j + T] = max(dp[j] + I, dp[j + T]);
    }

    int answer = 0;
    for (int i : dp)
        answer = max(i, answer);
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}