/*
    BOJ 6236 용돈 관리
    https://www.acmicpc.net/problem/6236
*/

#include <algorithm>
#include <iostream>

#define MAX 100001
#define INF 987654321

using namespace std;

int n, m, sum;
int answer = INF;
int arr[MAX];

bool check(int mid) {  // mid 는 인출 금액 k 를 의미함
    int cnt = 1, temp = mid;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > mid) return false;  // 인출 금액보다 쓸 금액이 더 클때

        if (temp < arr[i]) {  // temp 는 배열 구간을 나누기 위한 변수임
            temp = mid;
            cnt++;
        }
        temp -= arr[i];
    }
    return cnt <= m;
}

void search() {
    int left = 1, right = sum;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            // 인출 금액이 더 큰 경우 더 적은 인출금액으로 좁히기
            right = mid - 1;
            answer = min(answer, mid);  // 인출금액이 i번째 금액이상이어야 생존가능
        } else {
            // 인출 금액이 더 작은 경우 더 큰 금액으로 늘리기
            left = mid + 1;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    search();
    cout << answer;

    return 0;
}