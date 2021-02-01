/*
    BOJ 15961 회전 초밥
    https://www.acmicpc.net/problem/15961
*/

#include <bits/stdc++.h>

#define MAX_N 3000001
#define MAX_D 3001

using namespace std;

int N, D, K, C;      // 초밥접시수, 가짓수, 연속해서 먹는 접시의 수, 쿠폰번호
int arr[MAX_N];      // 초밥 정보를 담은 배열 (원형 큐 대신에 그냥 배열로)
int visited[MAX_D];  // 먹은 초밥에 대해 처리하기 위해 사용되는 배열

void solve() {
    int total = 0, max_num = 0;    // 초밥 종류를 세는 변수, 최대 가짓수.
    for (int i = 0; i < K; ++i) {  // k 개의 접시를 돌면서, 각 초밥의 종류를 카운팅함.
        if (!visited[arr[i]]) total++;
        visited[arr[i]]++;
    }

    max_num = total;

    for (int i = 1; i < N; ++i) {  // 먹는 갯수 카운팅
        if (max_num <= total) {
            if (!visited[C])
                max_num = total + 1;  // 쿠폰 초밥을 먹지 않았을때
            else
                max_num = total;
        }

        visited[arr[i - 1]]--;              // 해당 초밥에 담긴 갯수를 담는 배열이므로, 먹었기에 하나 줄임
        if (!visited[arr[i - 1]]) total--;  // 해당 초밥이 큐에 없을때, 종류를 하나 줄임

        // (i + K - 1) % N 은 회전초밥이므로, 원형으로 순회시키기 위함임.
        if (!visited[arr[(i + K - 1) % N]]) total++;  // 다음차례의 초밥을 한번도 먹지 않았으면 종류늘림.
        visited[arr[(i + K - 1) % N]]++;
    }

    cout << max_num;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> D >> K >> C;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    solve();

    return 0;
}
