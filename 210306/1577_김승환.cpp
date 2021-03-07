#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    N++; M++;
    vector<vector<bool>> down(M, vector<bool>(N)), right(M, vector<bool>(N));
    for (int i=0; i<K; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < c)
            right[b][a] = true;
        else if (c < a)
            right[d][c] = true;
        if (b < d)
            down[b][a] = true;
        else if (d < b)
            down[d][c] = true;
    }

    vector<vector<ll>> v(M, vector<ll>(N));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    v[0][0] = 1;
    while (!q.empty())
    {
        const int y = q.front().first, x = q.front().second;
        if (y < M-1 && !down[y][x])
        {
            if (v[y+1][x] == 0)
                q.emplace(y+1, x);
            v[y+1][x] += v[y][x];
        }
        if (x < N-1 && !right[y][x])
        {
            if (v[y][x+1] == 0)
                q.emplace(y, x+1);
            v[y][x+1] += v[y][x];
        }
        q.pop();
    }
    cout << v[M-1][N-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}