#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> times(N);
    for (int i=0; i<N; ++i)
        cin >> times[i].first >> times[i].second;
    sort(times.begin(), times.end(), [] (auto a, auto b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    int count, end;
    count = end = 0;
    for (auto i : times)
    {
        if (i.first >= end)
        {
            count++;
            end = i.second;
        }
    }
    cout << count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}