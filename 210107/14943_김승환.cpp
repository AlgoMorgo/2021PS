/**
 * boj 14943 벼룩 시장
 * 사고 파는 벼룩의 합이 같으므로 어떻게든 거래 수요는 충족되어야 한다
 * 결국 왼쪽부터 채워나간다면 모든 거래가 최소 비용으로 이루어진다는 발상
 * 직관적으로 짰더니 시간복잡도를 어떻게 계산해야할지 모르겠다
 * 정답 코드를 봤는데 훨씬 더 좋은 풀이가 많다...
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<pair<int, int>> buyers, sellers;
    for (int i=0; i<N; ++i)
    {
        int value;
        cin >> value;
        if (value < 0)
            buyers.emplace_back(i, -value);
        else if (value > 0)
            sellers.emplace_back(i, value);
    }

    long long answer = 0;
    int start = 0;
    for (auto seller : sellers)
    {
        for (int i=start; i<buyers.size(); ++i)
        {
            // 거래량은 두 사람이 원하는 거래량 중 작은 것으로
            int volume = min(seller.second, buyers[i].second);
            answer += abs(seller.first - buyers[i].first) * volume;
            buyers[i].second -= volume;
            seller.second -= volume;
            // 이미 거래량을 충족한 구매자는 넘어가자
            if (buyers[i].second == 0)
                start++;
            if (seller.second == 0)
                break;
        }
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}