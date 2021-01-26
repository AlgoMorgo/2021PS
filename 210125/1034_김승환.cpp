#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, M, K;
    cin >> N >> M;
    vector<string> row(N);
    for (auto& i : row)
        cin >> i;
    cin >> K;

    int answer = 0;
    for (int i=0; i<N; ++i)
    {
        int off = 0;
        for (int j=0; j<M; ++j)
            off += row[i][j] == '0' ? 1 : 0;
        if (K >= off && (K - off) % 2 == 0)
        {
            int count = 0;
            for (int j=0; j<N; ++j)
                count += row[i] == row[j];
            answer = max(count, answer);
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