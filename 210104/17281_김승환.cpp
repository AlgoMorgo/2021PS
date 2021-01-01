/**
 * boj 17281 ⚾
 * 8! * 3e1 <= 1.2e6이므로 하드코딩해도 충분하다고 판단
 * 타순 수열을 만들기 위해 dfs를 사용했음
 */

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> check(9);
vector<vector<int>> expect;
vector<int> member(9);

void dfs(int depth)
{
    if (depth == 3) // 4번 타자는 정해져 있다
        dfs(4);
    else if (depth == 9)
    {
        // 타순이 정해졌을 때, 점수 계산
        int point, out, player;
        bool f, s, t;
        point = player = 0;
        for (int i=0; i<N; ++i)
        {
            out = f = s = t = false;
            while (true) // 아웃을 기록하는 타자가 한 명은 있다
            {
                if (expect[i][member[player]] == 1)
                {
                    point += t;
                    t = s;
                    s = f;
                    f = true;
                }
                else if (expect[i][member[player]] == 2)
                {
                    point += t + s;
                    t = f;
                    s = true;
                    f = false;
                }
                else if (expect[i][member[player]] == 3)
                {
                    point += t + s + f;
                    t = true;
                    s = f = false;
                }
                else if (expect[i][member[player]] == 4)
                {
                    point += t + s + f + 1;
                    t = s = f = false;
                }
                else
                    out++;

                player = (player+1)%9;
                if (out == 3)
                    break;
            }
        }
        M = point > M ? point : M;
    }
    else
    {
        for (int i=0; i<9; ++i)
        {
            if (check[i])
                continue;

            check[i] = true;
            member[depth] = i;
            dfs(depth+1);
            check[i] = false;
        }
    }
}

void solve()
{
    cin >> N;
    for (int i=0; i<N; ++i)
    {
        expect.emplace_back(9);
        for (int j=0; j<9; ++j)
            cin >> expect[i][j];
    }

    check[0] = true;
    member[3] = 0;
    dfs(0);
    cout << M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}