/**
 * boj 2170 선 긋기
 * 유명한 스위핑 문제
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N;
    vector<pair<int, int>> points;

    cin >> N;
    for (int i=0; i<N; ++i)
    {
        int s, e;
        cin >> s >> e;
        points.emplace_back(s, e);
    }

    sort(points.begin(), points.end());
    int length, start, end;
    length = 0;
    start = points[0].first;
    end = points[0].second;
    for (int i=1; i<N; ++i)
    {
        if (points[i].first > end)
        {
            length += end - start;
            start = points[i].first;
        }
        end = points[i].second > end ? points[i].second : end;
    }
    length += end - start;

    cout << length;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}