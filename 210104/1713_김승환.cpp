/**
 * 1713 후보 추천하기
 * N, K(쿼리의 개수)가 매우 작아 단순 구현 문제로 추측
 * 하드코딩하였음
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;

    // 인덱스가 1부터 시작해서 헷갈린다
    // 배열을 K+1잡고 초기화는 -1로 했는데, 잘 생각하면 K개 -1 초기화나 K+1개 0 초기화로도 가능할 것
    vector<int> counts(101), date(101), photos(N, -1);
    for (int i=0; i<K; ++i)
    {
        int person;
        cin >> person;
        counts[person]++;

        // 후보로 이미 선정되어 있으면 카운트만 넘기고 탈출
        // 개선할 방법이 뭐가 있을까? 함수로 래핑하거나 goto문 사용?
        bool check = false;
        for (int j=0; j<N; ++j)
        {
            if (photos[j] == person)
            {
                check = true;
                break;
            }
        }
        if (check)
            continue;

        // 빈 사진 칸이 있는지 체크
        int valid = -1;
        for (int j=0; j<N; ++j)
        {
            if (photos[j] == -1)
            {
                valid = j;
                break;
            }
        }

        if (valid != -1)
        {
            photos[valid] = person;
            date[person] = i;
        }
        else // 빈 사진 칸이 없으면 가장 카운트가 적은 후보를 삭제하고 넣는다
        {
            int min_index = 0;
            for (int j=1; j<N; ++j)
            {
                if (counts[photos[min_index]] > counts[photos[j]])
                    min_index = j;
                else if (counts[photos[min_index]] == counts[photos[j]])
                {
                    if (date[photos[min_index]] > date[photos[j]])
                        min_index = j;
                }
            }
            counts[photos[min_index]] = 0;
            photos[min_index] = person;
            date[person] = i;
        }
    }

    sort(photos.begin(), photos.end());
    for (int i=0; i<N-1; ++i)
        cout << photos[i] << " ";
    cout << photos[N-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}