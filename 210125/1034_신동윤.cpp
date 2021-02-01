/*
    BOJ 1034 램프
    https://www.acmicpc.net/problem/1034
*/

#include <algorithm>
#include <iostream>
#include <string>

#define MAX 51

using namespace std;

int n, m, k, answer;
string adj[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> adj[i];
    }

    cin >> k;

    for (int i = 0; i < n; ++i) {
        int zero_num = 0, same_row = 0;
        for (int j = 0; j < m; ++j) {
            if (adj[i][j] == '0')
                zero_num++;
        }

        if (zero_num > k || zero_num % 2 != k % 2) continue;

        for (int j = 0; j < n; ++j) {
            if (adj[i] == adj[j])
                same_row++;
        }

        answer = max(answer, same_row);
    }

    cout << answer;
    return 0;
}