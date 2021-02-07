#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, A;
    cin >> N;
    vector<pair<int, int>> stack;
    vector<int> answer(N, -1);
    cin >> A;
    stack.emplace_back(0, A);
    for (int i=1; i<N; ++i)
    {
        cin >> A;
        while (!stack.empty())
        {
            if (stack.back().second < A)
            {
                answer[stack.back().first] = A;
                stack.pop_back();
            }
            else
                break;
        }
        stack.emplace_back(i, A);
    }
    cout << answer[0];
    for (int i=1; i<answer.size(); ++i)
        cout << ' ' << answer[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}