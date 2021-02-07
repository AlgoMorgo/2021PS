#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;

void solve()
{
    vector<vector<char>> s(5, vector<char>(5));
    for (auto& v : s)
    {
        for (char& c : v)
            cin >> c;
    }

    vector<pair<int, int>> pos(7);
    auto check = [&] () -> bool
    {
        vector<bool> conn(7);
        function<void (int)> dfs = [&] (int x)
        {
            conn[x] = true;
            for (int i=0; i<7; ++i)
            {
                if (i == x || conn[i])
                    continue;
                if (pos[x].first == pos[i].first)
                {
                    if (abs(pos[x].second - pos[i].second) == 1)
                        dfs(i);
                }
                if (pos[x].second == pos[i].second)
                {
                    if (abs(pos[x].first - pos[i].first) == 1)
                        dfs(i);
                }
            }
        };
        dfs(0);

        int count = 0;
        for (bool b : conn)
            count += b;
        if (count < 7)
            return false;

        count = 0;
        for (auto& p : pos)
            count += (s[p.second][p.first] == 'S');
        if (count < 4)
            return false;

        return true;
    };
    int answer = 0;
    for (int i=0; i<19; ++i)
    {
        for (int j=i+1; j<20; ++j)
        {
            for (int k=j+1; k<21; ++k)
            {
                for (int l=k+1; l<22; ++l)
                {
                    for (int m=l+1; m<23; ++m)
                    {
                        for (int n=m+1; n<24; ++n)
                        {
                            for (int o=n+1; o<25; ++o)
                            {
                                pos[0].first = i%5; pos[0].second = i/5;
                                pos[1].first = j%5; pos[1].second = j/5;
                                pos[2].first = k%5; pos[2].second = k/5;
                                pos[3].first = l%5; pos[3].second = l/5;
                                pos[4].first = m%5; pos[4].second = m/5;
                                pos[5].first = n%5; pos[5].second = n/5;
                                pos[6].first = o%5; pos[6].second = o/5;
                                answer += check();
                            }
                        }
                    }
                }
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