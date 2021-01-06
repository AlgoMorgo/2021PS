/**
 * boj 17135 캐슬 디펜스
 * 15C3 * 3 * M * 100, 최악의 경우에도 연산이 아주 적어 하드코딩 가능
 * 15C3 (궁수 위치), 3 (궁수 수), M (최대 턴 수), 100 (최대 공격범위 넓이)
 * 저번 스터디 야구 문제와 비슷한 접근
 * 2차원 행렬 다루기와 예외 처리 등 구현력 평가 문제인듯
 * for문이 너무 깊어서 goto문을 잘 쓰면 가독성이 좋아질 것 같다, 그래도 안쓰고 만들어봄
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int N, M, D;
    cin >> N >> M >> D;

    vector<vector<int>> init(N, vector<int>(M));
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
            cin >> init[i][j];
    }

    // 처음으로 적이 나오는 y 좌표 전처리
    int firstLineEnemyAppeared = N;
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            if (init[i][j] == 1)
            {
                firstLineEnemyAppeared = i;
                break;
            }
        }
        if (firstLineEnemyAppeared == i)
            break;
    }

    int archers[3], answer = 0;
    // 이번에는 DFS 대신 for문만으로 조합을 만들어봄
    for (archers[0]=0; archers[0]<M-2; ++archers[0])
    {
        for (archers[1]=archers[0]+1; archers[1]<M-1; ++archers[1])
        {
            for (archers[2]=archers[1]+1; archers[2]<M; ++archers[2])
            {
                // 초기 보드 상태는 저장되어야하므로 복사하자
                vector<vector<int>> board = init;
                int killed = 0;

                // 최대 턴 수는 행의 개수 N과 처음으로 적이 등장하는 y좌표의 차
                for (int turn=firstLineEnemyAppeared; turn<N; ++turn)
                {
                    pair<int, int> targets[3];
                    bool flags[3];
                    // 궁수마다 공격 계산하기
                    for (int i=0; i<3; ++i)
                    {
                        flags[i] = false;
                        for (int d=0; d<D; ++d)
                        {
                            for (int t=0; t<2*d+1; ++t)
                            {
                                // 조건에 맞게 공격 범위를 검사해주자 (너무 매직 넘버인가?)
                                int y, x;
                                y = N-1-d+abs(t-d);
                                x = archers[i]-d+t;

                                if (y < 0 || y > N-1 || x < 0 || x > M-1)
                                    continue;
                                if (board[y][x])
                                {
                                    // 적 하나를 동시에 공격할 수 있으므로 타겟 지정 후 처리는 따로
                                    targets[i] = make_pair(y, x);
                                    flags[i] = true;
                                    break;
                                }
                            }
                            if (flags[i])
                                break;
                        }
                    }

                    // 타겟 처치 처리
                    for (int i=0; i<3; ++i)
                    {
                        if (!flags[i])
                            continue;
                        if (board[targets[i].first][targets[i].second])
                        {
                            board[targets[i].first][targets[i].second] = 0;
                            killed++;
                        }
                    }

                    // 적은 전진한다
                    for (int y=N-1; y>=0; --y)
                    {
                        for (int x=0; x<M; ++x)
                        {
                            if (board[y][x] && y < N-1)
                                board[y+1][x] = 1;
                            board[y][x] = 0;
                        }
                    }

                }

                answer = max(killed, answer);
            }
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