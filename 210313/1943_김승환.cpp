#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> coins(N);
    int target = 0;
    for (auto& p : coins)
    {
        cin >> p.first >> p.second;
        target += p.first * p.second;
    }

    if (target%2)
    {
        cout << 0 << '\n';
        return;
    }

    vector<bool> dp(target/2+1);
    dp[0] = true;
    int start = 0;
    for (auto& p : coins)
    {
        int i = 1;
        while (p.second > 0)
        {
            for (int c=min(start, target/2-p.first*i); c>=0; --c)
            {
                if (dp[c])
                    dp[c+p.first*i] = true;
            }
            start += p.first*i;
            p.second -= i;
            i = min(i << 1, p.second);
        }
    }
    cout << dp[target/2] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; T = 3;
    while (T--)
        solve();
    return 0;
}