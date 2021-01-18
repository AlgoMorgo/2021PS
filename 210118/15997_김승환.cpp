#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct game
{
    int a, b;
    double prob[3];
};

unordered_map<string, int> map;
game games[6];
int score[4];
double acc = 1, answer[4];

void dfs(int depth)
{
    if (depth == 6)
    {
        int left = 2, high = 9;
        while (left > 0)
        {
            int o = 0;
            for (int s : score)
            {
                if (s == high)
                    o++;
            }
            if (o > 1)
            {
                for (int i=0; i<4; ++i)
                {
                    if (score[i] == high)
                        answer[i] += acc*left/o;
                }
                left = 0;
            }
            else if (o == 1)
            {
                for (int i=0; i<4; ++i)
                {
                    if (score[i] == high)
                    {
                        answer[i] += acc;
                        break;
                    }
                }
                left--;
            }
            high--;
        }
    }
    else
    {
        double temp = acc;
        for (int i=0; i<3; ++i)
        {
            if (games[depth].prob[i] < 0.001)
                continue;
            acc *= games[depth].prob[i];
            switch (i)
            {
                case 0:
                    score[games[depth].a] += 3;
                    break;
                case 1:
                    score[games[depth].a]++;
                    score[games[depth].b]++;
                    break;
                case 2:
                    score[games[depth].b] += 3;
                    break;
            }
            dfs(depth+1);
            switch (i)
            {
                case 0:
                    score[games[depth].a] -= 3;
                    break;
                case 1:
                    score[games[depth].a]--;
                    score[games[depth].b]--;
                    break;
                case 2:
                    score[games[depth].b] -= 3;
                    break;
            }
            acc = temp;
        }
    }
}

void solve()
{
    for (int i=0; i<4; ++i)
    {
        string str;
        cin >> str;
        map[str] = i;
    }
    for (int i=0; i<6; ++i)
    {
        string sa, sb;
        cin >> sa >> sb;
        games[i].a = map[sa];
        games[i].b = map[sb];
        for (int j=0; j<3; ++j)
            cin >> games[i].prob[j];
    }
    dfs(0);
    cout.precision(10);
    for (double i : answer)
        cout << i << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}