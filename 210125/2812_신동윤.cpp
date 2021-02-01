/*
    BOJ 2812 크게 만들기
    https://www.acmicpc.net/problem/2812
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n, k;
string str;
stack<char> st;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    cin >> str;

    for (int i = 0; i < str.length(); ++i) {
        while (k && !st.empty() && st.top() < str[i]) {
            st.pop();
            k--;
        }
        st.push(str[i]);
    }

    while (k--) st.pop();

    string answer;
    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }

    reverse(answer.begin(), answer.end());
    cout << answer;

    return 0;
}