#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, S;
    cin >> N >> S;
    vector<pair<int, int>> v(N+1);
    v[0].first = -2e9;
    for (int i=1; i<=N; ++i)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<int> dp(N+1);
    for (int i=1; i<=N; ++i)
    {
        int prev = upper_bound(v.begin(), v.end(), make_pair(v[i].first-S+1, 0)) - v.begin();
        if (prev == i)
            dp[i] = dp[i-1] + v[i].second;
        else
            dp[i] = max(dp[prev - 1] + v[i].second, dp[i - 1]);
    }
    cout << dp[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}