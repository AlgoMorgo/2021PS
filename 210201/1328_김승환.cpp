#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

void solve()
{
    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(L+1, vector<ll>(R+1)));
    dp[1][1][1] = 1;
    for (int i=2; i<=N; ++i)
    {
        for (int l=1; l<=L; ++l)
        {
            for (int r=1; r<=R; ++r)
            {
                dp[i][l][r] = dp[i-1][l-1][r] + dp[i-1][l][r-1] + dp[i-1][l][r] * (i-2);
                dp[i][l][r] %= (ll)1e9+7;
            }
        }
    }
    cout << dp[N][L][R];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}