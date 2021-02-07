/*
    BOJ 17298 오큰수
    https://www.acmicpc.net/problem/17298
*/

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> vec;
stack<int> st;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    vector<int> answer(vec.size(), -1);

    for (int i = 0; i < vec.size(); ++i) {
        while (!st.empty() && vec[st.top()] < vec[i]) {
            answer[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}