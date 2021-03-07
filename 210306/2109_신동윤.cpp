#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, P, D, answer;
vector<pair<int, int>> vec;  // D, P 순서

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first > p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    int max_day = -1;
    for (int i = 0; i < N; ++i) {
        cin >> P >> D;
        vec.push_back({D, P});
        max_day = max(max_day, vec[i].first);
    }

    sort(vec.begin(), vec.end(), comp);

    priority_queue<int> pq;

    int idx = 0;
    for (int day = max_day; day >= 1; --day) {
        while (idx < N && day <= vec[idx].first) {
            pq.push(vec[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}