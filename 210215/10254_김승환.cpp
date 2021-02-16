#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
    int x, y, p, q;

    void input()
    {
        cin >> x >> y;
        p = q = 0;
    }

    bool operator<(const point& other)
    {
        if (1LL * p * other.q != 1LL * q * other.p)
            return 1LL * p * other.q > 1LL * q * other.p;
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

bool ccw(const point& a1, const point& a2, const point& b1, const point& b2)
{
    return 1LL * (a2.x - a1.x) * (b2.y - b1.y) > 1LL * (a2.y - a1.y) * (b2.x - b1.x);
}

void solve()
{
    int N;
    cin >> N;

    vector<point> v(N);
    for (int i=0; i<N; ++i)
        v[i].input();

    // convex hull
    swap(v[0], *min_element(v.begin(), v.end()));
    for(int i=1; i<N; ++i)
    {
        v[i].p = v[i].x - v[0].x;
        v[i].q = v[i].y - v[0].y;
    }
    sort(v.begin()+1, v.end());

    vector<point> hull;
    for (int i=0; i<N; ++i)
    {
        while (hull.size() >= 2 && !ccw(hull[hull.size()-2], hull.back(), v[i]))
            hull.pop_back();
        hull.push_back(v[i]);
    }

    // rotating calipers
    auto dist = [] (const point& a, const point& b)
    {
        return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
    };
    long long maximum = 0;
    int ans1, ans2;
    for (int i=0, j=1; i<hull.size();)
    {
        if (maximum < dist(hull[i], hull[j]))
        {
            maximum = dist(hull[i], hull[j]);
            ans1 = i;
            ans2 = j;
        }
        if (j < hull.size()-1 && ccw(hull[i], hull[i+1], hull[j], hull[j+1]))
            j++;
        else
            i++;
    }

    cout << hull[ans1].x << ' ' << hull[ans1].y << ' ' << hull[ans2].x << ' ' << hull[ans2].y << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}