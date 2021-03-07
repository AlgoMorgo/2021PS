#include <iostream>

#define MAX 1001

using namespace std;

int N;
int adj[MAX][MAX];
int degree[MAX];

void dfs(int node) {
    for (int i = 1; i <= N; ++i) {
        while (adj[node][i]) {
            adj[node][i]--;
            adj[i][node]--;
            dfs(i);
        }
    }
    cout << node << " ";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> adj[i][j];

            degree[i] += adj[i][j];
            degree[j] += adj[i][j];
        }
    }

    bool isEuler = true;

    for (int i = 1; i <= N; ++i) {
        degree[i] /= 2;  // 양방향 간선

        if (degree[i] % 2) {
            isEuler = false;
            break;
        }
    }

    if (isEuler) {
        dfs(1);
    } else {
        cout << "-1";
    }

    return 0;
}