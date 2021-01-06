/**
 * boj 9252 LCS 2
 * 문자열 관련 DP, N*M (각 문자열의 길이)
 * LCS 문자열을 찾아내는 과정이 까다롭다
 * DP 값을 역추적한다는게 포인트
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;

    string lcs;
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1));
    for (int i=a.length()-1; i>=0; --i)
    {
        for (int j=b.length()-1; j>=0; --j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i+1][j+1] + 1;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    cout << dp[0][0] << endl;

    int y, x;
    y = x = 0;
    while (dp[y][x] != 0)
    {
        if (dp[y][x] == dp[y+1][x])
            y++;
        else if (dp[y][x] == dp[y][x+1])
            x++;
        else // if (dp[y][x] == dp[y+1][x+1] + 1 인데 생략 가능
        {
            // DP 점화식에서 역추적한다는 아이디어
            // 생각보다 많은 DP에서 활용될 수 있어보이니 잘 기억하자
            cout << b[x];
            y++;
            x++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}