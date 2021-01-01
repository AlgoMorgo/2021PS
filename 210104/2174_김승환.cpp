/**
 * boj 2174 Crashing Robots
 * M * repeat * N <= 1e6이므로 하드코딩해도 충분하다고 판단
 * 무조건 로봇은 한 칸에 하나이므로 메모이제이션을 통해 O(M * repeat)으로 줄일 수 있음
 */

#include <iostream>
#include <vector>

using namespace std;

struct robot
{
    int x, y;
    char d;
};

void solve()
{
    int A, B, N, M;
    cin >> A >> B >> N >> M;

    vector<robot> robots;
    robots.resize(N);
    for (int i=0; i<N; ++i)
        cin >> robots[i].x >> robots[i].y >> robots[i].d;
    for (int i=0; i<M; ++i)
    {
        int index, repeat;
        char action;
        cin >> index >> action >> repeat;
        index--;
        for (int r=0; r<repeat; ++r)
        {
            if (action == 'L')
            {
                if (robots[index].d == 'E')
                    robots[index].d = 'N';
                else if (robots[index].d == 'W')
                    robots[index].d = 'S';
                else if (robots[index].d == 'S')
                    robots[index].d = 'E';
                else if (robots[index].d == 'N')
                    robots[index].d = 'W';
            }
            else if (action == 'R')
            {
                if (robots[index].d == 'E')
                    robots[index].d = 'S';
                else if (robots[index].d == 'W')
                    robots[index].d = 'N';
                else if (robots[index].d == 'S')
                    robots[index].d = 'W';
                else if (robots[index].d == 'N')
                    robots[index].d = 'E';
            }
            else if (action == 'F')
            {
                if (robots[index].d == 'E')
                    robots[index].x++;
                else if (robots[index].d == 'W')
                    robots[index].x--;
                else if (robots[index].d == 'S')
                    robots[index].y--;
                else if (robots[index].d == 'N')
                    robots[index].y++;

                if (robots[index].x == 0 || robots[index].x == A+1
                    || robots[index].y == 0 || robots[index].y == B+1)
                {
                    cout << "Robot " << index+1 << " crashes into the wall";
                    return;
                }

                // 메모이제이션을 통해 O(1)로 최적화할 수 있음
                for (int j=0; j<N; ++j)
                {
                    if (j == index)
                        continue;
                    if (robots[j].x == robots[index].x && robots[j].y == robots[index].y)
                    {
                        cout << "Robot " << index+1 << " crashes into robot " << j+1;
                        return;
                    }
                }
            }
        }
    }

    cout << "OK";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}