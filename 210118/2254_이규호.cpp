#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
#define MAX 1000

struct Point
{
    int x, y, p, q;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y), p(1), q(0) {}

    bool operator==(Point& A)
    {
        return (x == A.x) && (y == A.y);
    }
};

bool comp(const Point & A, const Point & B)
{
    if (1LL * A.q * B.p != 1LL * A.p * B.q)
        return 1LL * A.q * B.p < 1LL * A.p * B.q;

    if (A.y != B.y)
        return A.y < B.y;

    return A.x < B.x;
}

int ccw(const Point & A, const Point & B, const Point & C)
{
    ll tmp = (1LL * A.x * B.y + 1LL * B.x * C.y + 1LL * C.x * A.y - 1LL * B.x * A.y - 1LL * C.x * B.y - 1LL * A.x * C.y);
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

int N, x, y, px, py, ans = 0;
bool ok = true;
vector<Point> v;
Point P;

void input()
{
    CIN3(N, px, py);
    P = Point(px, py);
    v.resize(N);
    FUP(i, 0, N - 1)
    {
        CIN2(x, y);
        v[i] = Point(x, y);
    }
}

bool convex_hull(vector<Point> arr)
{
    int n = arr.size();
    if (n < 3) return false;
    sort(ALL(arr), comp); // y좌표, x좌표가 작은 순으로 정렬

    FUP(i, 1, n - 1) // 기준점으로부터 상대 위치 계산
    {
        arr[i].p = arr[i].x - arr[0].x;
        arr[i].q = arr[i].y - arr[0].y;
    }
    auto it = arr.begin();
    it++;
    sort(it, arr.end(), comp); // 반시계 방향으로 다시 정렬
    stack<int> S;
    S.push(0);
    S.push(1);
    int next = 2;
    while (next < n)
    {
        while (S.size() >= 2)
        {
            int first, second;
            second = S.top();
            S.pop();
            first = S.top();

            // first, second, next가 좌회전 ( > 0 )이라면 second push
            // 우회전( < 0 )이라면 위의 while문 계속 반복
            if (ccw(arr[first], arr[second], arr[next]) > 0)
            {
                S.push(second);
                break;
            }
        }
        // next push
        S.push(next++);
    }
    if (S.size() < 3) return false;
    set<int> have;
    int first = S.top(); S.pop();
    int start = first;
    int second = S.top(); S.pop();
    have.insert(first); have.insert(second);
    int direct = ccw(arr[first], arr[second], P);
    while (!S.empty())
    {
        first = second;
        second = S.top();
        have.insert(second);
        S.pop();
        if (direct != ccw(arr[first], arr[second], P)) return false;
    }
    if (direct != ccw(arr[second], arr[start], P)) return false;
    vector<Point> newV;
    FUP(i, 0, n - 1)
    {
        if (!have.count(i))
        {
            newV.push_back(arr[i]);
        }
    }
    v = newV;
    ans++;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    while (convex_hull(v)) {}
    COUT(ans);
    
    return 0;
}