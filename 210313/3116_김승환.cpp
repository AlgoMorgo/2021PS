#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> pos(N);
    vector<int> d(N);
    for (int i=0; i<N; ++i)
    {
        cin >> pos[i].first >> pos[i].second;
        cin >> d[i];
    }

    auto h = [&] (int i)
    {
        if (d[i] == 1 || d[i] == 8 || d[i] == 7)
            return -1;
        else if (d[i] == 3 || d[i] == 4 || d[i] == 5)
            return 1;
        return 0;
    };
    auto v = [&] (int i)
    {
        if (d[i] == 1 || d[i] == 2 || d[i] == 3)
            return 1;
        else if (d[i] == 5 || d[i] == 6 || d[i] == 7)
            return -1;
        return 0;
    };
    vector<tuple<int, int, int, int, int>> meets;
    for (int i=0; i<N; ++i)
    {
        for (int j=i+1; j<N; ++j)
        {
            int x, y, dx, dy;
            x = pos[j].first - pos[i].first;
            y = pos[j].second - pos[i].second;
            dx = dy = 0;

            dx += h(i);
            dx -= h(j);
            dy += v(i);
            dy -= v(j);

            int tx, ty;
            if (x == 0 && dy != 0 && y%dy == 0 && y/dy > 0)
                meets.emplace_back(y/dy, pos[i].first + h(i)*y/dy, pos[i].second + v(i)*y/dy, i, j);
            else if (y == 0 && dx != 0 && x%dx == 0 && x/dx > 0)
                meets.emplace_back(x/dx, pos[i].first + h(i)*x/dx, pos[i].second + v(i)*x/dx, i, j);
            else if (x != 0 && y != 0 && dy != 0 && dx != 0 && y%dy == 0 && x%dx == 0 && y/dy == x/dx && y/dy > 0)
                meets.emplace_back(y/dy, pos[i].first + h(i)*y/dy, pos[i].second + v(i)*y/dy, i, j);
        }
    }

    sort(meets.begin(), meets.end());
    vector<bool> check(N);
    int answer, time, count, current, cx, cy;
    answer = count = 0;
    current = cx = cy = -1;
    for (auto& tup : meets)
    {
        int t, x, y, i, j;
        tie(t, x, y, i, j) = tup;
        if (t != current || cx != x || cy != y)
        {
            if (answer < count)
            {
                answer = count;
                time = current;
            }
            current = t;
            cx = x;
            cy = y;
            fill(check.begin(), check.end(), false);
            check[i] = true;
            check[j] = true;
            count = 2;
        }
        else
        {
            if (!check[i])
            {
                check[i] = true;
                count++;
            }
            if (!check[j])
            {
                check[j] = true;
                count++;
            }
        }
    }
    if (answer < count)
    {
        answer = count;
        time = current;
    }
    cout << answer << endl << time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}