#include <bits/stdc++.h>
using namespace std;

int N, ym_front[300000], yM_front[300000], ym_back[300000], yM_back[300000];
pair<int, int> xy[300000];

// calc two pointer
bool calc(int d)
{
    int start = 0, end = 1;
    while (true)
    {
        if (start == end)
            break;

        if (xy[end-1].first - xy[start].first <= d)
        {
            if (start == 0 && end == N)
                return true;
            else
            {
                int ym = 1e9, yM = -1e9;
                if (start > 0)
                {
                    ym = ym_front[start-1];
                    yM = yM_front[start-1];
                }
                if (end < N)
                {
                    ym = min(ym, ym_back[end]);
                    yM = max(yM, yM_back[end]);
                }
                if (yM - ym <= d)
                    return true;
            }
        }

        if (xy[end-1].first - xy[start].first <= d && end < N)
            end++;
        else
            start++;
    }

    return false;
}

void solve()
{
    cin >> N;
    if (N < 3)
    {
        cout << "0.0";
        return;
    }

    for (int i=0; i<N; ++i)
        cin >> xy[i].first >> xy[i].second;
    sort(xy, xy+N);

    // pre process
    ym_front[0] = yM_front[0] = xy[0].second;
    ym_back[N-1] = yM_back[N-1] = xy[N-1].second;
    for (int i=1; i<N; ++i)
    {
        ym_front[i] = min(ym_front[i-1], xy[i].second);
        yM_front[i] = max(yM_front[i-1], xy[i].second);
        ym_back[N-1-i] = min(ym_back[N-i], xy[N-1-i].second);
        yM_back[N-1-i] = max(yM_back[N-i], xy[N-1-i].second);
    }

    // binary search for distance
    long long left = 0, right = 2e9;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (calc(mid))
            right = mid;
        else
            left = mid+1;
    }

    cout << (long long)right*5/10 << '.' << (long long)right*5%10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}