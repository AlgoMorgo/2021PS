#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    string start, end;
    cin >> N >> start >> end;
    vector<vector<int>> v(N, vector<int>(10, -1));
    vector<vector<bool>> trace(N, vector<bool>(10));
    function<int (int, int)> calc = [&] (int depth, int go)
    {
        if (v[depth][go] != -1)
            return v[depth][go];

        int left, right;

        if (depth == N-1)
        {
            left = (end[depth] - start[depth] + 20 - go) % 10;
            right = (start[depth] - end[depth] + 10 + go) % 10;
        }
        else
        {
            left = (end[depth] - start[depth] + 20 - go) % 10;
            left += calc(depth+1, (go+left)%10);
            right = (start[depth] - end[depth] + 10 + go) % 10 + calc(depth+1, go);
        }

        if (left < right)
        {
            trace[depth][go] = true;
            return v[depth][go] = left;
        }
        else
            return v[depth][go] = right;
    };

    cout << calc(0, 0) << '\n';
    int go = 0;
    for (int i=0; i<N; ++i)
    {
        int temp;
        if (trace[i][go])
        {
            temp = (end[i] - start[i] + 20 - go) % 10;
            go = (go+temp)%10;
        }
        else
        {
            temp = (start[i] - end[i] + 10 + go) % 10;
            temp = -temp;
        }
        if (temp == 0)
            continue;
        cout << i+1 << ' ' << temp << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}