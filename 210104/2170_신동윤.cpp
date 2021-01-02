/*
    BOJ 2170 선 긋기
    https://www.acmicpc.net/problem/2170
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector<pair<int, int>> vec;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        vec.push_back({start, end});
    }

    sort(vec.begin(), vec.end(), comp);  // 시작좌표 기준 오름차순 정렬

    int start = vec[0].first, end = vec[0].second;
    for (int i = 1; i < vec.size(); ++i) {
        if (start <= vec[i].first && vec[i].first <= end && end < vec[i].second) {
            // 다음 좌표 쌍의 시작좌표가 이전 좌표내의 범위에 있고, 끝좌표가 이전좌표의 끝보다는 클때 길이 갱신 가능
            end = vec[i].second;
        } else if (vec[i].first > end) {
            // 다음 좌표 쌍의 시작표가 이전 좌표내의 범위를 벗어났을때 (끊긴 선)
            answer += (end - start);
            start = vec[i].first;
            end = vec[i].second;
        }
    }

    answer += (end - start);
    cout << answer;

    return 0;
}