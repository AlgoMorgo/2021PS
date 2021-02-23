#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int R, C;
    cin >> R >> C;
    vector<string> m(R);
    for (string& s : m)
        cin >> s;

    pair<int, int> start, end;
    bool found = false;
    for (int y=0; y<R; ++y)
    {
        for (int x=0; x<C; ++x)
        {
            if (m[y][x] == 'L')
            {
                if (!found)
                {
                    start.first = y;
                    start.second = x;
                    found = true;
                }
                else
                {
                    end.first = y;
                    end.second = x;
                    break;
                }
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> v(R, vector<int>(C));
    vector<vector<bool>> visited(R, vector<bool>(C));
    for (int y=0; y<R; ++y)
    {
        for (int x=0; x<C; ++x)
        {
            if (m[y][x] != 'X')
            {
                if (y > 0 && m[y-1][x] == 'X' && !visited[y-1][x])
                {
                    q.emplace(y-1, x);
                    v[y-1][x] = 1;
                    visited[y-1][x] = true;
                }
                if (y < R-1 && m[y+1][x] == 'X' && !visited[y+1][x])
                {
                    q.emplace(y+1, x);
                    v[y+1][x] = 1;
                    visited[y+1][x] = true;
                }
                if (x > 0 && m[y][x-1] == 'X' && !visited[y][x-1])
                {
                    q.emplace(y, x-1);
                    v[y][x-1] = 1;
                    visited[y][x-1] = true;
                }
                if (x < C-1 && m[y][x+1] == 'X' && !visited[y][x+1])
                {
                    q.emplace(y, x+1);
                    v[y][x+1] = 1;
                    visited[y][x+1] = true;
                }
            }
        }
    }

    int s = 0, e = 0;
    while (!q.empty())
    {
        const int y = q.front().first;
        const int x = q.front().second;
        q.pop();

        if (v[y][x] > e)
            e = v[y][x];
        if (y > 0 && m[y-1][x] == 'X' && !visited[y-1][x])
        {
            q.emplace(y-1, x);
            v[y-1][x] = v[y][x]+1;
            visited[y-1][x] = true;
        }
        if (y < R-1 && m[y+1][x] == 'X' && !visited[y+1][x])
        {
            q.emplace(y+1, x);
            v[y+1][x] = v[y][x]+1;
            visited[y+1][x] = true;
        }
        if (x > 0 && m[y][x-1] == 'X' && !visited[y][x-1])
        {
            q.emplace(y, x-1);
            v[y][x-1] = v[y][x]+1;
            visited[y][x-1] = true;
        }
        if (x < C-1 && m[y][x+1] == 'X' && !visited[y][x+1])
        {
            q.emplace(y, x+1);
            v[y][x+1] = v[y][x]+1;
            visited[y][x+1] = true;
        }
    }

    auto check = [&] (int k) -> bool
    {
        visited.clear();
        for (int i=0; i<R; ++i)
            visited.emplace_back(C);
        q.emplace(start.first, start.second);
        visited[start.first][start.second] = true;

        while (!q.empty())
        {
            const int y = q.front().first;
            const int x = q.front().second;
            q.pop();

            if (y == end.first && x == end.second)
            {
                while (!q.empty())
                    q.pop();
                return true;
            }
            if (y > 0 && v[y-1][x] <= k && !visited[y-1][x])
            {
                q.emplace(y-1, x);
                visited[y-1][x] = true;
            }
            if (y < R-1 && v[y+1][x] <= k && !visited[y+1][x])
            {
                q.emplace(y+1, x);
                visited[y+1][x] = true;
            }
            if (x > 0 && v[y][x-1] <= k && !visited[y][x-1])
            {
                q.emplace(y, x-1);
                visited[y][x-1] = true;
            }
            if (x < C-1 && v[y][x+1] <= k && !visited[y][x+1])
            {
                q.emplace(y, x+1);
                visited[y][x+1] = true;
            }
        }

        return false;
    };

    while (s < e)
    {
        const int mid = (s+e)/2;
        if (check(mid))
            e = mid;
        else
            s = mid+1;
    }
    cout << e;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}