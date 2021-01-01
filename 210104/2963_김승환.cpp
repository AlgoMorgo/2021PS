/**
 * boj 2964 SETNJA
 * Big Integer 구현해보기
 * '*' 쿼리가 특이하므로 주의
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct bigint
{
    const int Q = 1e9;
    vector<int> num;

    bigint() = default;
    bigint(int i) { num.push_back(i); }
    bigint(bigint& t) { num.assign(t.num.begin(), t.num.end()); }

    void operator += (bigint& other)
    {
        bool quotient = false;
        for (int i=0; i<num.size() || i<other.num.size() || quotient; ++i)
        {
            if (i >= num.size())
                num.push_back(0);
            if (i < other.num.size())
                num[i] += other.num[i];

            num[i] += quotient;
            if (num[i] >= Q)
            {
                num[i] -= Q;
                quotient = true;
            }
            else
                quotient = false;
        }
    }

    void operator *= (int k)
    {
        // 덧셈으로 곱셈을 빠르게 구현하기
        bigint origin(*this);
        for (int i=k; i>1; i/=2)
            *this += *this;
        if (k%2)
            *this += origin;
    }
};

void solve()
{
    string input;
    cin >> input;

    bigint value(1), count(1);
    for (char c : input)
    {
        if (c == '*')
        {
            value *= 5;
            value += count;
            // 처리할 노드가 3배씩 늘어난다
            count *= 3;
        }
        else if (c == 'R')
        {
            value *= 2;
            value += count;
        }
        else if (c == 'L')
            value *= 2;
    }

    auto iter = value.num.rbegin();
    cout << *iter;
    cout << setfill('0');
    for (++iter; iter!=value.num.rend(); ++iter)
        cout << setw(9) << *iter;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}