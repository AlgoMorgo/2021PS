#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<vector<int>> bamboo(N, vector<int>(N));
    vector<pair<int, int>> pos;
    for (int y=0; y<N; ++y)
    {
        for (int x=0; x<N; ++x)
        {
            cin >> bamboo[y][x];
            pos.emplace_back(y, x);
        }
    }
    sort(pos.begin(), pos.end(), [&bamboo] (auto& a, auto& b) -> bool
    {
        return bamboo[a.first][a.second] > bamboo[b.first][b.second];
    });
    vector<vector<int>> count(N, vector<int>(N, 1));
    for (auto& p : pos)
    {
        const int y = p.first, x = p.second;
        if (y > 0 && bamboo[y][x] > bamboo[y-1][x])
            count[y-1][x] = max(count[y-1][x], count[y][x]+1);
        if (y < N-1 && bamboo[y][x] > bamboo[y+1][x])
            count[y+1][x] = max(count[y+1][x], count[y][x]+1);
        if (x > 0 && bamboo[y][x] > bamboo[y][x-1])
            count[y][x-1] = max(count[y][x-1], count[y][x]+1);
        if (x < N-1 && bamboo[y][x] > bamboo[y][x+1])
            count[y][x+1] = max(count[y][x+1], count[y][x]+1);
    }
    int answer = 0;
    for (auto& ys : count)
    {
        for (int x : ys)
        {
            if (x > answer)
                answer = x;
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