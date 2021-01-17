/*
    BOJ 1276 교각 놓기
    https://www.acmicpc.net/problem/1276
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x1;
    int x2;
} Pos;

vector<Pos> vec;

int n, answer;

bool comp(Pos& p1, Pos& p2) {
    return p1.y > p2.y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        Pos temp;
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        temp.y = y;
        temp.x1 = x1;
        temp.x2 = x2;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < n; ++i) {
        answer += 2 * vec[i].y;
        int x1 = vec[i].x1, x2 = vec[i].x2 - 1;
        for (int j = i + 1; j < n; ++j) {
            if (x1 >= vec[j].x1 && x1 < vec[j].x2) {
                answer -= vec[j].y;
                break;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (x2 >= vec[j].x1 && x2 < vec[j].x2) {
                answer -= vec[j].y;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}