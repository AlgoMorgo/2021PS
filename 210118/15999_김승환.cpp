#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    for (auto& ys : board)
    {
        for (char& x : ys)
            cin >> x;
    }
    int count = 0;
    for (int y=0; y<N; ++y)
    {
        for (int x=0; x<M; ++x)
        {
            if (x > 0 && board[y][x-1] != board[y][x])
                continue;
            if (x < M-1 && board[y][x+1] != board[y][x])
                continue;
            if (y > 0 && board[y-1][x] != board[y][x])
                continue;
            if (y < N-1 && board[y+1][x] != board[y][x])
                continue;
            count++;
        }
    }
    int answer = 1;
    for (int i=0; i<count; ++i)
        answer = (answer + answer) % (int)(1e9+7);
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}