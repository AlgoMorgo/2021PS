/*
    BOJ 1937 욕심쟁이 판다
    https://www.acmicpc.net/problem/1937
*/

#include <algorithm>
#include <iostream>

#define MAX 500

using namespace std;

int n, answer;
int adj[MAX][MAX], days[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int dfs(int r, int c) {
    if (days[r][c])
        return days[r][c];

    days[r][c] = 1;

    for (int i = 0; i < 4; ++i) {
        int ny = r + dy[i], nx = c + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (adj[ny][nx] > adj[r][c])
            days[r][c] = max(days[r][c], dfs(ny, nx) + 1);
    }

    return days[r][c];
}

void solve() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            answer = max(answer, dfs(i, j));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    solve();

    cout << answer;

    return 0;
}