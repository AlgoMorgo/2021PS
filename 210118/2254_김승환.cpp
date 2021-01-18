#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
    int x, y, p, q;
    point() { x = y = p = q = 0; }
    bool operator < (const point& other)
    {
        if (1LL * other.p * q != 1LL * p * other.q)
            return 1LL * other.p * q < 1LL * p * other.q;
        else if (y != other.y)
            return y < other.y;
        else
            return x < other.x;
    }
};

bool ccw(const point& a, const point& b, const point& c)
{
    return 1LL * (b.x - a.x) * (c.y - b.y) > 1LL * (b.y - a.y) * (c.x - b.x);
}

void solve()
{
    int N;
    cin >> N;

    point jail;
    cin >> jail.x >> jail.y;

    vector<point> points(N);
    for (int i=0; i<N; ++i)
        cin >> points[i].x >> points[i].y;

    int answer = 0;
    while (points.size() > 2)
    {
        for (point& point : points)
            point.p = point.q = 0;

        swap(points[0], *min_element(points.begin(), points.end()));
        for (int i=1; i<points.size(); ++i)
        {
            points[i].p = points[i].x - points[0].x;
            points[i].q = points[i].y - points[0].y;
        }
        sort(points.begin()+1, points.end());

        vector<int> hull;
        for (int i=0; i<points.size(); ++i)
        {
            while (hull.size() >= 2 && !ccw(points[hull[hull.size()-2]], points[hull.back()], points[i]))
                hull.pop_back();
            hull.push_back(i);
        }

        if (hull.size() < 3)
            break;

        bool in = true;
        for (int i=0; i<hull.size()-1; ++i)
        {
            if (!ccw(points[hull[i]], points[hull[i+1]], jail))
            {
                in = false;
                break;
            }
        }
        if (!in || !ccw(points[hull.back()], points[hull[0]], jail))
            break;

        answer++;

        vector<bool> used(points.size());
        for (int i : hull)
            used[i] = true;
        vector<point> remain;
        for (int i=0; i<points.size(); ++i)
        {
            if (!used[i])
                remain.push_back(points[i]);
        }
        points = remain;
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