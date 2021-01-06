/**
 * boj 12430 생존자(Large)
 * p + s로 정렬하는게 핵심 아이디어
 * 이후 dp를 돌리면 됨, 그래프 등 다른 방향으로 생각해볼 수도
 * 좀 요상한 문제... 시간 제한이 왜 통과가 되는건지 모르겠음
 * 빡빡하게 통과되는 것 같음, 구현에 따라 널널하게 통과되는 것 같기도 함
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<pair<int, int>> ps;
    for (int i=0; i<N; ++i)
    {
        int p, s;
        cin >> p >> s;
        ps.emplace_back(p, s);
    }
    // p + s로 정렬 (식량의 최대 끝 점으로 정렬, 이래야 최댓값이 나오는 순서가 보장됨)
    sort(ps.begin(), ps.end(), [] (auto a, auto b) { return a.first + a.second < b.first + b.second; });

    vector<bool> dp(ps[N-1].first + ps[N-1].second + 1);
    dp[0] = dp[ps[0].second] = true;
    for (int i=1; i<N; ++i)
    {
        for (int j=ps[i].first; j>=0; --j)
        {
            if (dp[j])
                dp[j + ps[i].second] = true;
            /*
             * dp[j + ps[i].second] = dp[j] 하니 시간초과;;
             * 논리상 같더라도 연산 자체를 줄이는 방향으로 가자
             * 컴파일러가 최적화 해줄 줄 알았는데 아닌가봄
             * if를 줄여서 어셈블리에 jump를 최소화하자고 생각했는데,
             * jump가 일어나더라도 연산 자체가 줄어들면 훨씬 빠른가보다
             * 나중에 godbolt에 넣어서 분석해보자
             */
        }
    }

    int i;
    for (i=ps[N-1].first + ps[N-1].second; i>=0; --i)
    {
        if (dp[i])
            break;
    }
    cout << i << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i=1; i<=T; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}