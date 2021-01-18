#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> pos(N);
    for (int& i : pos)
        cin >> i;
    sort(pos.begin(), pos.end());
    int answer, maxpos, z;
    answer = maxpos = 0;
    z = lower_bound(pos.begin(), pos.end(), 0) - pos.begin();
    for (int i=pos.size()-1; i>=z; i-=M)
    {
        answer += pos[i];
        maxpos = max(maxpos, pos[i]);
    }
    for (int i=0; i<z; i+=M)
    {
        answer -= pos[i];
        maxpos = max(maxpos, -pos[i]);
    }
    cout << 2*answer-maxpos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}