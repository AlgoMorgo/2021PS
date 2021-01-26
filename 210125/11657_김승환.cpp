#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> bus(N);
    for (int i=0; i<M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        bus[a].push_back(make_pair(b, c));
    }
    vector<long long> dp(N, 1e9);
    dp[0] = 0;
    for (int i=0; i<N-1; ++i)
    {
        for (int v=0; v<N; ++v)
        {
            if (dp[v] == 1e9)
                continue;
            for (auto& e : bus[v])
            {
                if (dp[e.first] > dp[v] + e.second)
                    dp[e.first] = dp[v] + e.second;
            }
        }
    }
    for (int v=0; v<N; ++v)
    {
        if (dp[v] == 1e9)
            continue;
        for (auto& e : bus[v])
        {
            if (dp[e.first] > dp[v] + e.second)
            {
                cout << -1;
                return;
            }
        }
    }
    for (int i=1; i<N; ++i)
        cout << (dp[i] == 1e9 ? -1 : dp[i]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}