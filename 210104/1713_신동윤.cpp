/*
    BOJ 1713 후보 추천하기
    https://www.acmicpc.net/problem/1713
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Student {
   public:
    int number;
    int recommend;
    int time;
    Student(int _number, int _recommend, int _time);
};

Student::Student(int _number, int _recommend, int _time) {
    number = _number;
    recommend = _recommend;
    time = _time;
}

int N, M;  // 사진틀의 전체 크기, 학생 입력 총 횟수

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> M;

    vector<Student> pictures;

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;  // 학생 번호

        // 먼저 해당 학생 번호가 사진틀에 있는지 확인한다.
        bool flag = false;
        int idx = 0;
        for (int j = 0; j < pictures.size(); ++j) {
            if (pictures[j].number == num) {
                idx = j;
                flag = true;
                break;
            }
        }

        if (flag)
            pictures[idx].recommend++;  // 이미 사진이 걸려있는 학생이 있을때
        else {
            if (pictures.size() < N)
                pictures.push_back(Student(num, 1, i));  // 사진틀 자리가 남을때
            else {
                // 자리가 남지 않을때
                int _recommend = 1001, _time = 1001;  // 추천 횟수와 게시된 시간을 파악해야됨
                for (int j = 0; j < pictures.size(); ++j) {
                    if (_recommend > pictures[j].recommend) {  // 추천횟수가 제일적은 것을 찾고
                        _recommend = pictures[j].recommend;
                        _time = pictures[j].time;
                        idx = j;
                    } else if (_recommend == pictures[j].recommend) {
                        if (_time > pictures[j].time) {  // 추천횟수가 작으면서 시간도 앞선경
                            _time = pictures[j].time;
                            idx = j;
                        }
                    }
                }
                Student temp(num, 1, i);
                pictures[idx] = temp;  // 새로운 학생으로 교체
            }
        }
    }

    vector<int> answer;
    for (int i = 0; i < N; ++i) answer.push_back(pictures[i].number);
    sort(answer.begin(), answer.end());
    for (int i = 0; i < N; ++i) cout << answer[i] << " ";

    return 0;
}