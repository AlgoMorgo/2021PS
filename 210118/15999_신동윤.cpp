/*
    BOJ 15999 뒤집기
    https://www.acmicpc.net/problem/15999
*/

#include <iostream>

#define MAX 2001

using namespace std;

const int MOD = 1000000007;
int n, m;
char adj[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> adj[i][j];

    int cnt = 0;
    // 2000 * 2000 * 4 => 시간내에 가능
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k], nx = j + dx[k];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (adj[i][j] != adj[ny][nx]) {
                    cnt++;
                    break;
                }
            }
        }
    }

    int answer = 1;
    for (int i = 0; i < (n * m) - cnt; ++i)
        answer = (answer * 2) % MOD;

    cout << answer;

    return 0;
}