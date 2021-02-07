#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct edge
{
    int v, c, d;
    edge(int V, int C, int D) : v(V), c(C), d(D) {};
};

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<edge>> edges(N);
    for (int i=0; i<K; ++i)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        u--; v--;
        edges[u].emplace_back(v, c, d);
    }
    vector<vector<int>> dp(N, vector<int>(M+1, 1e9));
    dp[0][0] = 0;
    auto comp = [] (edge& a, edge& b) { return a.d > b.d; };
    priority_queue<edge, vector<edge>, decltype(comp)> pq(comp);
    pq.emplace(0, 0, 0);
    while (!pq.empty())
    {
        const edge top = pq.top();
        if (dp[top.v][top.c] == top.d)
        {
            for (edge& e : edges[top.v])
            {
                if (top.c+e.c > M)
                    continue;
                if (dp[e.v][top.c+e.c] > top.d + e.d)
                {
                    dp[e.v][top.c+e.c] = top.d + e.d;
                    pq.emplace(e.v, top.c+e.c, top.d+e.d);
                }
            }
        }
        pq.pop();
    }
    int answer = 1e9;
    for (int m=M; m>=0; --m)
        answer = min(dp[N-1][m], answer);
    cout << (answer != 1e9 ? to_string(answer) : "Poor KCM") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}