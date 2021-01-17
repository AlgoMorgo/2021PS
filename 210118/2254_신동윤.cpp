/*
    BOJ 2254 감옥 건설
    https://www.acmicpc.net/problem/2254
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    int p, q;

    Point() {}
    Point(int x1, int y1, int p1 = 0, int q1 = 0) : x(x1), y(y1), p(p1), q(q1) {}

    bool operator<(const Point& O) {
        if (1LL * q * O.p != 1LL * p * O.q) return 1LL * q * O.p < 1LL * p * O.q;
        if (y != O.y) return y < O.y;
        return x < O.x;
    }
};

long long ccw(const Point& A, const Point& B, const Point& C) {
    long long temp = 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
    if (temp < 0)
        return -1;
    else if (temp == 0)
        return 0;
    else
        return 1;
}

vector<Point> vec;
int n, answer;
Point prison;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    cin >> prison.x >> prison.y;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vec.push_back(Point(x, y));
    }

    while (1) {
        // 아래는 convex hull 을 판별 하는 기능
        // y 좌표 -> x 좌표 순으로 정렬 (가장 아래의 왼쪽에 있는 점이 0번점으로)
        sort(vec.begin(), vec.end());

        for (int i = 1; i < vec.size(); ++i) {
            vec[i].p = vec[i].x - vec[0].x;
            vec[i].q = vec[i].y - vec[0].y;
        }

        // 0번 점을 제외한 나머지 점을 반시계방향 정렬
        sort(++vec.begin(), vec.end());

        vector<Point> backup_vec = vec;  // convex hull 을 한번 찾으면 다른 좌표에 대해서도 찾아야 하므로 백업본이 필요함.
        stack<int> st, backup;
        st.push(0);
        st.push(1);

        int next = 2;

        while (next < vec.size()) {
            while (st.size() >= 2) {
                int first, second;
                second = st.top();
                st.pop();
                first = st.top();
                if (ccw(vec[first], vec[second], vec[next]) > 0) {
                    st.push(second);
                    break;
                }
            }
            st.push(next++);
        }

        // st 에 convex hull 에 해당하는 좌표들이 모두 담김
        // 아래는 px, py 가 convex hull 에 포함되는지 파악하는 기능

        backup = st;
        int start = st.top();
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();

        long long check = ccw(vec[first], vec[second], prison);
        bool inner = true;

        while (!st.empty()) {
            first = second;  // 스택 순회하면서 다음 점으로 넘어가면서 ccw 파악
            second = st.top();
            st.pop();

            if (check != ccw(vec[first], vec[second], prison)) {
                inner = false;
                break;
            }
        }

        // 시작점과 끝나는점도 ccw 를 해야함.
        if (check != ccw(vec[second], vec[start], prison))
            inner = false;

        // 감옥이 convex hull 내부에 있으면
        if (inner) {
            answer++;

            // 이전 convex hull 에 사용되었던 좌표를빼고 초기화함.
            set<int> idx;
            for (int i = 0; i < vec.size(); ++i) idx.insert(i);

            while (!backup.empty()) {
                idx.erase(backup.top());
                backup.pop();
            }

            // 입력 받았던 좌표중 사용된 좌표는 제거하고 나머지만 추가.
            vec.clear();
            for (auto iter = idx.begin(); iter != idx.end(); ++iter)
                vec.push_back(backup_vec[(*iter)]);

        } else {
            break;
        }

        if (vec.size() < 3) break;
    }

    cout << answer;

    return 0;
}