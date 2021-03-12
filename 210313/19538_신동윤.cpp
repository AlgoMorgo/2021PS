#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 200001

using namespace std;

int N, M;                 // 사람수, 최초 유포자 수
vector<int> adj[MAX];     // 인접행렬
int rumor[MAX];           // 루머 믿는 시간
queue<pair<int, int>> q;  // 노드 번호, 시간

void solve() {
    while (!q.empty()) {
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        for (auto next_node : adj[node]) {
            if (rumor[next_node] == -1) {  // 최초 유포자가 아닌 경우
                int cnt = 0;               // 인접한 대상 중 루머 믿는 사람 몇명인지 갯수 세기

                for (auto next_next_node : adj[next_node]) {
                    if (~rumor[next_next_node] && rumor[next_next_node] <= time) cnt += 1;
                }

                int next_node_size = adj[next_node].size();  // 다음 노드의 전체 인접한 노드 수 중에서
                int half = next_node_size / 2;               // 절반을 추려냄

                if (next_node_size % 2 == 1) half += 1;  // 다만 홀수 일땐 짝홀 맞춰야하고

                if (cnt >= half) {  // 절반이상이 믿고 있으면 갱신
                    rumor[next_node] = time + 1;
                    q.push({next_node, time + 1});
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    int num;
    for (int i = 1; i <= N; ++i) {
        while (1) {
            cin >> num;
            if (num == 0) break;
            adj[i].push_back(num);
        }
    }

    memset(rumor, -1, sizeof(rumor));

    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> num;
        rumor[num] = 0;
        q.push({num, 0});
    }

    solve();

    for (int i = 1; i <= N; ++i) cout << rumor[i] << " ";

    return 0;
}