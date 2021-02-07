/*
    BOJ 1918 후위 표기식
    https://www.acmicpc.net/problem/1918
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
string input, answer;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if ('A' <= input[i] && input[i] <= 'Z') {  // 피연산자
            answer.push_back(input[i]);
        } else {  // 사칙연산자
            switch (input[i]) {
                case '*':
                case '/':
                    while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                        answer.push_back(st.top());
                        st.pop();
                    }
                    st.push(input[i]);
                    break;
                case '+':
                case '-':
                    while (!st.empty() && st.top() != '(') {
                        answer.push_back(st.top());
                        st.pop();
                    }
                    st.push(input[i]);
                    break;
                case '(':
                    st.push(input[i]);
                    break;
                case ')':
                    while (!st.empty() && st.top() != '(') {
                        answer.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                    break;
            }
        }
    }

    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }

    cout << answer;

    return 0;
}