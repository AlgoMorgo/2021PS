#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;
    vector<string> v(N);
    for (string& s : v)
        cin >> s;
    vector<vector<bool>> visited(N, vector<bool>(N));
    function<void (int, int)> dfs = [&] (int y, int x)
    {
        visited[y][x] = true;
        if (y > 0 && v[y-1][x] == v[y][x] && !visited[y-1][x])
            dfs(y-1, x);
        if (y < N-1 && v[y+1][x] == v[y][x] && !visited[y+1][x])
            dfs(y+1, x);
        if (x > 0 && v[y][x-1] == v[y][x] && !visited[y][x-1])
            dfs(y, x-1);
        if (x < N-1 && v[y][x+1] == v[y][x] && !visited[y][x+1])
            dfs(y, x+1);
    };
    int normal = 0, rg = 0;
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                normal++;
            }
        }
    }
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            visited[i][j] = false;
            if (v[i][j] == 'G')
                v[i][j] = 'R';
        }
    }
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                rg++;
            }
        }
    }
    cout << normal << ' ' << rg;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}