#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> gem;  // 무게, 가치
vector<int> backpack;

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first < p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int m, v;
        cin >> m >> v;
        gem.push_back({m, v});
    }

    for (int i = 0; i < K; ++i) {
        int c;
        cin >> c;
        backpack.push_back(c);
    }

    sort(gem.begin(), gem.end(), comp);      // 보석 무게 오름차순
    sort(backpack.begin(), backpack.end());  // 가방 무게 오름차순

    priority_queue<int> pq;

    int idx = 0;
    long long answer = 0;  // 30만* 백만 이 최대가 될 수 있음

    for (int i = 0; i < K; ++i) {
        while (idx < N && backpack[i] >= gem[idx].first) {
            pq.push(gem[idx].second);  // 보석 가치를 넣어서 최대힙 정렬
            idx++;
        }

        if (!pq.empty()) {
            answer += (long long)pq.top();  // 최대 가치를 가진 보석만 추출
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}
