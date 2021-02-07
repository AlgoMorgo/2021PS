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
    int N, M, D, E;
    cin >> N >> M >> D >> E;
    vector<int> h(N);
    for (int& i : h)
        cin >> i;
    vector<vector<pair<int, int>>> edges(N);
    for (int i=0; i<M; ++i)
    {
        int a, b, n;
        cin >> a >> b >> n; a--; b--;
        edges[a].emplace_back(b, n);
        edges[b].emplace_back(a, n);
    }

    vector<ll> inc(N, 1e18);
    priority_queue<pair<ll, int>> pq;
    inc[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty())
    {
        const ll cost = -pq.top().first;
        const int dest = pq.top().second;

        if (inc[dest] == cost)
        {
            for (auto& p : edges[dest])
            {
                if (h[dest] < h[p.first] && inc[p.first] > inc[dest] + p.second*D)
                {
                    inc[p.first] = inc[dest] + p.second*D;
                    pq.emplace(-inc[p.first], p.first);
                }
            }
        }
        pq.pop();
    }
    vector<ll> dec(N, 1e18);
    dec[N-1] = 0;
    pq.emplace(0, N-1);
    while (!pq.empty())
    {
        const ll cost = -pq.top().first;
        const int dest = pq.top().second;

        if (dec[dest] == cost)
        {
            for (auto& p : edges[dest])
            {
                if (h[dest] < h[p.first] && dec[p.first] > dec[dest] + p.second*D)
                {
                    dec[p.first] = dec[dest] + p.second*D;
                    pq.emplace(-dec[p.first], p.first);
                }
            }
        }
        pq.pop();
    }

    ll answer = -1e18;
    for (int i=1; i<N-1; ++i)
    {
        if (inc[i] == 1e18 || dec[i] == 1e18)
            continue;
        answer = max(1LL * E * h[i] - inc[i] - dec[i], answer);
    }
    cout << (answer == -1e18 ? "Impossible" : to_string(answer));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}