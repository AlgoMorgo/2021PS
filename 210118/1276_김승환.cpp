#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct br
{
    int x1, x2, y;
    bool operator<(const br& other) const
    {
        return y < other.y;
    }
};

void solve()
{
    int N;
    cin >> N;
    vector<br> brs(N);
    for (auto& i : brs)
        cin >> i.y >> i.x1 >> i.x2;
    sort(brs.begin(), brs.end());
    vector<int> height(10001);
    int answer = 0;
    for (auto& i : brs)
    {
        answer += i.y - height[i.x1];
        answer += i.y - height[i.x2-1];
        for (int j=i.x1; j<i.x2; ++j)
            height[j] = i.y;
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