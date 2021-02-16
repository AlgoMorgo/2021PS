#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

struct Info {
    int from, to, cnt;
};

int N, C, M, answer;  // 마을 수, 트럭용량, 박스정보갯수
Info arr[MAX];
int capacity[MAX];  // capacity[i] : j => i 번째에서 적재한 양 j

// 도착지, 출발지 순으로 정렬 (도착지 우선)
bool comp(Info& a, Info& b) {
    if (a.to < b.to)
        return true;
    else if (a.to == b.to) {
        if (a.from < b.from) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> C >> M;
    for (int i = 0; i < M; ++i) {
        cin >> arr[i].from >> arr[i].to >> arr[i].cnt;
    }

    sort(arr, arr + M, comp);

    // 전체 박스를 순회하면서 트럭이 담는 최대양 계산
    for (int i = 0; i < M; ++i) {
        int max_num = 0;
        int from = arr[i].from, to = arr[i].to, weight = arr[i].cnt;

        // 시작지 ~ 끝지점에서 가장많이 적재된 양을 구함
        for (int j = from; j < to; ++j) {
            max_num = max(capacity[j], max_num);
        }

        int temp = min(weight, C - max_num);  // 더 적재 가능한 양 파악
        answer += temp;

        // 트럭에 적재한 무게 추가
        for (int j = from; j < to; ++j) {
            capacity[j] += temp;
        }
    }

    cout << answer;

    return 0;
}
