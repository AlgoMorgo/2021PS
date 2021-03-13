#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;
    vector<vector<int>> edges(N);
    for (int i=0; i<N; ++i)
    {
        int t;
        cin >> t;
        while (t != 0)
        {
            edges[i].push_back(--t);
            cin >> t;
        }
    }

    int M;
    cin >> M;
    vector<int> answer(N, -1);
    vector<int> num(N);
    vector<queue<int>> qs(2);
    for (int i=0; i<M; ++i)
    {
        int t;
        cin >> t;
        answer[--t] = 0;
        qs[0].push(t);
    }

    int time = 0;
    bool b = false;
    while (!qs[0].empty() || !qs[1].empty())
    {
        time++;
        while (!qs[b].empty())
        {
            for (int i : edges[qs[b].front()])
            {
                num[i]++;
                if (answer[i] == -1 && num[i] >= edges[i].size()/2 + edges[i].size()%2)
                {
                    answer[i] = time;
                    qs[!b].push(i);
                }
            }
            qs[b].pop();
        }
        b = !b;
    }
    cout << answer[0];
    for (int i=1; i<N; ++i)
        cout << ' ' << answer[i];
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}