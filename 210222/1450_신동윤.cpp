#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, C, answer;           // 물건갯수, 가방 최대 용량, 답
ll stuff[31];              // 물건 정보
vector<ll> first, second;  // 두 그룹으로 나눠서 반반 탐색

void recursion(int s, int e, vector<ll>& vec, ll sum) {  // 절반씩 나눠서 두 그룹으로 분배하기 위한 재귀함수
    if (s > e) {
        vec.push_back(sum);
        return;
    }

    recursion(s + 1, e, vec, sum);
    recursion(s + 1, e, vec, sum + stuff[s]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> C;

    for (int i = 0; i < N; ++i) cin >> stuff[i];

    recursion(0, N / 2, first, 0);  // 절반씩 나눠서 탐색
    recursion(N / 2 + 1, N - 1, second, 0);

    sort(second.begin(), second.end());  // upper_bound 는 이진탐색 기반이므로 이미 정렬되어 있는 상태여야함.

    for (int i = 0; i < first.size(); ++i) {
        answer += upper_bound(second.begin(), second.end(), C - first[i]) - second.begin();  // 두번째 그룹의 시작과 끝에서 C - first[i] 를 초과하는 값 - 두번째 그룹의
    }

    cout << answer;

    return 0;
}
