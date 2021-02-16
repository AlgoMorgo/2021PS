#include <bits/stdc++.h>

using namespace std;

int n, k;                   // 센서 수, 집중국 갯수
vector<int> vec, distList;  // 센서 좌표 리스트,  센서 간 거리 리스트

bool comp(int& a, int& b) {
    return a > b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    if (k >= n) {  // 집중국이 센서 갯수보다 많은경우 예외처리
        cout << "0";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());  // 센서를 오름 차순 정렬 (일직선 상에 연결되어 있으므로)

    int total = vec[n - 1] - vec[0];  // 전체 거리

    for (int i = 0; i < n - 1; ++i)
        distList.push_back(vec[i + 1] - vec[i]);  // 각 센서별 거리 담기

    sort(distList.begin(), distList.end(), comp);  // 각 센서별 거리 내림차순 정렬

    for (int i = 0; i < k - 1; ++i)  // k 개의 집중국 수신 가능 영역 계산
        total -= distList[i];

    cout << total;

    return 0;
}