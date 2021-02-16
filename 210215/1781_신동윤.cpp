#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<pair<int, int>> vec;  // 데드라인, 컵라면수

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        vec.push_back({x, y});
        --vec[i].first;  // 편의상 인덱스 맞추기 위해 하나뺌
    }

    sort(vec.begin(), vec.end());

    priority_queue<int> pq;  // 최대힙
    int idx = N - 1;

    for (int day = N - 1; day >= 0; --day) {
        while (idx >= 0 && vec[idx].first == day) {  // 같은 데드라인일때, 힙에 추가
            pq.push(vec[idx].second);
            idx--;
        }

        if (!pq.empty()) {  // 최댓값만 빼냄
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}
