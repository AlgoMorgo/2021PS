#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

void solve()
{
    while (true)
    {
        int N, M, S, D;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        cin >> S >> D;
        vector<vector<pair<int, int>>> edges(N);
        for (int i=0; i<M; ++i)
        {
            int u, v, p;
            cin >> u >> v >> p;
            edges[u].emplace_back(v, p);
        }

        vector<int> dp(N, 1e9);
        vector<vector<int>> prev(N);
        priority_queue<pair<int, int>> pq;
        dp[S] = 0;
        pq.emplace(0, S);
        while (!pq.empty())
        {
            const int cost = -pq.top().first, index = pq.top().second;
            if (dp[index] == cost)
            {
                for (auto& p : edges[index])
                {
                    if (dp[p.first] > dp[index] + p.second)
                    {
                        dp[p.first] = dp[index] + p.second;
                        prev[p.first].clear();
                        prev[p.first].push_back(index);
                        pq.emplace(-dp[p.first], p.first);
                    }
                    else if (dp[p.first] == dp[index] + p.second)
                        prev[p.first].push_back(index);
                }
            }
            pq.pop();
        }

        if (dp[D] == 1e9)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<vector<bool>> invalid(N, vector<bool>(N));
        vector<bool> visited(N);
        function<void (int)> dfs = [&] (int cur)
        {
            if (cur == S)
                return;
            visited[cur] = true;
            for (int i : prev[cur])
            {
                invalid[i][cur] = true;
                if (!visited[i])
                    dfs(i);
            }
        };
        dfs(D);

        for (int& i : dp)
            i = 1e9;
        dp[S] = 0;
        pq.emplace(0, S);
        while (!pq.empty())
        {
            const int cost = -pq.top().first, index = pq.top().second;
            if (dp[index] == cost)
            {
                for (auto& p : edges[index])
                {
                    if (invalid[index][p.first])
                        continue;
                    if (dp[p.first] > dp[index] + p.second)
                    {
                        dp[p.first] = dp[index] + p.second;
                        pq.emplace(-dp[p.first], p.first);
                    }
                }
            }
            pq.pop();
        }
        cout << (dp[D] != 1e9 ? dp[D] : -1) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int T; cin >> T;
//    while (T--)
    solve();
    return 0;
}