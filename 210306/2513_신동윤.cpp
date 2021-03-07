#include <algorithm>
#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int N, K, S, answer;               // 아파트 단지 수, 통학버스 정원, 학교위치
vector<pair<int, int>> apartment;  // 위치, 학생 수

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> S;

    for (int i = 0; i < N; ++i) {
        int pos, num;
        cin >> pos >> num;
        apartment.push_back({pos, num});
    }
    apartment.push_back({S, 0});

    sort(apartment.begin(), apartment.end());

    int idx = -1;
    for (int i = 0; i < apartment.size(); ++i)
        if (apartment[i].first == S)
            idx = i;

    // 좌측 탐색
    for (int i = 0; i < idx;) {
        int num = 0, j;
        for (j = i; j < idx; ++j) {
            num += apartment[j].second;
            if (num > K) {
                apartment[j].second = num - K;
                break;
            }
        }
        answer += (S - apartment[i].first) * 2;
        i = j;
    }

    // 우측 탐색
    for (int i = apartment.size() - 1; i > idx; --i) {
        int num = 0, j;
        for (j = i; j > idx; --j) {
            num += apartment[j].second;
            if (num > K) {
                apartment[j].second = num - K;
                j++;
                break;
            }
        }
        answer += (apartment[i].first - S) * 2;
        i = j;
    }

    cout << answer;

    return 0;
}