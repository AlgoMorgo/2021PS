#include <bits/stdc++.h>

using namespace std;

int N, answer;
int L, P;                            // 마을까지 거리, 기존 연료량
vector<pair<int, int>> gas_station;  // 주유소 까지 거리, 채울 수 있는 연료량

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        gas_station.push_back({a, b});
    }

    cin >> L >> P;

    sort(gas_station.begin(), gas_station.end());  // 주유소 까지 거리 기준 오름차순

    priority_queue<int> pq;

    // 현재 인덱스, 가지고 있는 연료량
    int idx = 0, cur_gas = P;

    while (cur_gas < L) {  // 목적지 거리보다 연료량이 적으면 주유소 가야됨
        while (idx < N && gas_station[idx].first <= cur_gas) {
            pq.push(gas_station[idx].second);
            idx++;
        }

        if (pq.empty()) {  // 더 이상 갈 수 없을때
            answer = -1;
            break;
        }

        cur_gas += pq.top();
        pq.pop();
        answer++;
    }

    cout << answer;

    return 0;
}
