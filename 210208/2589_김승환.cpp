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
    int H, W;
    cin >> H >> W;
    vector<vector<char>> b(H, vector<char>(W));
    for (auto& v : b)
    {
        for (char& c : v)
            cin >> c;
    }

    int answer = 0;

    for (int i=0; i<H; ++i)
    {
        for (int j=0; j<W; ++j)
        {
            if (b[i][j] == 'W')
                continue;
            vector<vector<char>> c = b;
            queue<tuple<int, int, int>> q;
            q.emplace(0, i, j);
            c[i][j] = 'W';
            while (!q.empty())
            {
                const int d = get<0>(q.front());
                const int y = get<1>(q.front());
                const int x = get<2>(q.front());
                if (d > answer)
                    answer = d;
                if (y > 0 && c[y-1][x] == 'L')
                {
                    q.emplace(d+1, y-1, x);
                    c[y-1][x] = 'W';
                }
                if (y < H-1 && c[y+1][x] == 'L')
                {
                    q.emplace(d+1, y+1, x);
                    c[y+1][x] = 'W';
                }
                if (x > 0 && c[y][x-1] == 'L')
                {
                    q.emplace(d+1, y, x-1);
                    c[y][x-1] = 'W';
                }
                if (x < W-1 && c[y][x+1] == 'L')
                {
                    q.emplace(d+1, y, x+1);
                    c[y][x+1] = 'W';
                }
                q.pop();
            }
        }
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