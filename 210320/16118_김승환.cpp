#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> edges(N);
    for (int i=0; i<M; ++i)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        edges[a].emplace_back(b, d);
        edges[b].emplace_back(a, d);
    }

    vector<vector<int>> wolf(N, vector<int>(2, 1e9));
    vector<int> fox(N, 1e9);
    priority_queue<tuple<int, int, int>> pq;
    wolf[0][0] = 0;
    pq.emplace(0, 0, 0);
    while (!pq.empty())
    {
        int dist, dest, flag;
        tie(dist, dest, flag) = pq.top();
        pq.pop();

        if (wolf[dest][flag] != -dist)
            continue;
        for (auto& p : edges[dest])
        {
            if (wolf[p.first][!flag] > wolf[dest][flag] + p.second + p.second * 3 * flag)
            {
                wolf[p.first][!flag] = wolf[dest][flag] + p.second + p.second * 3 * flag;
                pq.emplace(-wolf[p.first][!flag], p.first, !flag);
            }
        }
    }

    fox[0] = 0;
    pq.emplace(0, 0, 0);
    while (!pq.empty())
    {
        int dist, dest, temp;
        tie(dist, dest, temp) = pq.top();
        pq.pop();

        if (fox[dest] != -dist)
            continue;
        for (auto& p : edges[dest])
        {
            if (fox[p.first] > fox[dest] + 2 * p.second)
            {
                fox[p.first] = fox[dest] + 2 * p.second;
                pq.emplace(-fox[p.first], p.first, 0);
            }
        }
    }

    int answer = 0;
    for (int i=0; i<N; ++i)
    {
        if (fox[i] < wolf[i][0] && fox[i] < wolf[i][1])
            answer++;
    }
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}