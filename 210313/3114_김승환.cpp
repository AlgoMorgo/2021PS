#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M+1)), b(N, vector<int>(M+1));
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            char c;
            int k;
            cin >> c >> k;
            a[i][j+1] = a[i][j];
            b[i][j+1] = b[i][j];
            if (c == 'A')
                a[i][j+1] += k;
            else
                b[i][j+1] += k;
        }
    }
    vector<vector<int>> dp(N, vector<int>(M));
    function<int (int, int)> calc = [&] (int y, int x)
    {
        if (dp[y][x] != 0)
            return dp[y][x];
        if (y == N-1 && x == M-1)
            return a[N-1][M-1];
        if (y == N-1)
            return dp[y][x] = calc(y, x+1) - a[y][x+1] + a[y][x];

        int current = b[y][M] - b[y][x+1] + a[y][x];
        dp[y][x] = current + calc(y+1, x);
        if (x < M-1)
        {
            dp[y][x] = max(current + calc(y+1, x+1), dp[y][x]);
            dp[y][x] = max(calc(y, x+1) - a[y][x+1] + a[y][x], dp[y][x]);
        }

        return dp[y][x];
    };
    cout << calc(0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}