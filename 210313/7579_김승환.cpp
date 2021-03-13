#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> m(N), c(N);
    for (int& i : m)
        cin >> i;
    for (int& i : c)
        cin >> i;
    vector<int> dp(10001);
    dp[0] = 1;
    int start = 0;
    for (int i=0; i<N; ++i)
    {
        for (int j=start; j>=0; --j)
        {
            if (dp[j] > 0 && dp[j+c[i]] < dp[j] + m[i])
                dp[j+c[i]] = dp[j] + m[i];
        }
        start += c[i];
    }
    for (int i=0; i<=start; ++i)
    {
        if (dp[i] > M)
        {
            cout << i;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}