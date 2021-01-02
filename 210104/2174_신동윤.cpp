/*
    BOJ 2174 로봇 시뮬레이션
    https://www.acmicpc.net/problem/2174
*/

#include <cstdio>
#include <string>
#include <vector>

#define MAX 101

using namespace std;

int a, b, n, m;                             // a 는 열, b 는 행, n 은 로봇 좌표 갯수, m 은 명령어 입력 갯수
vector<pair<pair<int, int>, char>> robots;  // y, x, dir 순서
int map[MAX][MAX];
string error_msg;
bool flag;  // 명령어 수행 중 오류 발생 판별 변수

void l_order(int robot_idx) {  // 좌측 90도 회전
    char current_dir = robots[robot_idx].second;
    switch (current_dir) {
        case 'W':
            current_dir = 'S';
            robots[robot_idx].second = current_dir;
            break;
        case 'N':
            current_dir = 'W';
            robots[robot_idx].second = current_dir;
            break;
        case 'E':
            current_dir = 'N';
            robots[robot_idx].second = current_dir;
            break;
        case 'S':
            current_dir = 'E';
            robots[robot_idx].second = current_dir;
            break;
    }
}

void r_order(int robot_idx) {  // 우측 90도 회전
    char current_dir = robots[robot_idx].second;
    switch (current_dir) {
        case 'W':
            current_dir = 'N';
            robots[robot_idx].second = current_dir;
            break;
        case 'N':
            current_dir = 'E';
            robots[robot_idx].second = current_dir;
            break;
        case 'E':
            current_dir = 'S';
            robots[robot_idx].second = current_dir;
            break;
        case 'S':
            current_dir = 'W';
            robots[robot_idx].second = current_dir;
            break;
    }
}

void f_order(int robot_idx) {
    // move to forward
    int y = robots[robot_idx].first.first, x = robots[robot_idx].first.second;  // 입력 받을때, ((b - y + 1), x) 로 좌표값이 들어감
    int ny = y, nx = x;
    char current_dir = robots[robot_idx].second;
    string robot_num = to_string(robot_idx + 1), collision_idx;
    switch (current_dir) {
        case 'W':
            nx -= 1;
            if (nx <= 0) {
                error_msg = "Robot " + robot_num + " crashes into the wall";
                flag = true;
                break;
            } else if (map[ny][nx] == 1) {
                for (int i = 0; i < robots.size(); ++i) {
                    int r = robots[i].first.first, c = robots[i].first.second;
                    if (r == ny && c == nx) {
                        collision_idx = to_string(i + 1);
                        break;
                    }
                }
                error_msg = "Robot " + robot_num + " crashes into robot " + collision_idx;
                flag = true;
                break;
            }
            map[y][x] = 0;
            map[ny][nx] = 1;
            x = nx;
            robots[robot_idx].first.second = x;
            break;
        case 'N':
            ny -= 1;
            if (ny <= 0) {
                error_msg = "Robot " + robot_num + " crashes into the wall";
                flag = true;
                break;
            } else if (map[ny][nx] == 1) {
                for (int i = 0; i < robots.size(); ++i) {
                    int r = robots[i].first.first, c = robots[i].first.second;
                    if (r == ny && c == nx) {
                        collision_idx = to_string(i + 1);
                        break;
                    }
                }
                error_msg = "Robot " + robot_num + " crashes into robot " + collision_idx;
                flag = true;
                break;
            }
            map[y][x] = 0;
            map[ny][nx] = 1;
            y = ny;
            robots[robot_idx].first.first = y;
            break;
        case 'E':
            nx += 1;
            if (nx >= a + 1) {
                error_msg = "Robot " + robot_num + " crashes into the wall";
                flag = true;
                break;
            } else if (map[ny][nx] == 1) {
                for (int i = 0; i < robots.size(); ++i) {
                    int r = robots[i].first.first, c = robots[i].first.second;
                    if (r == ny && c == nx) {
                        collision_idx = to_string(i + 1);
                        break;
                    }
                }
                error_msg = "Robot " + robot_num + " crashes into robot " + collision_idx;
                flag = true;
                break;
            }
            map[y][x] = 0;
            map[ny][nx] = 1;
            x = nx;
            robots[robot_idx].first.second = x;
            break;
        case 'S':
            ny += 1;
            if (ny >= b + 1) {
                error_msg = "Robot " + robot_num + " crashes into the wall";
                flag = true;
                break;
            } else if (map[ny][nx] == 1) {
                for (int i = 0; i < robots.size(); ++i) {
                    int r = robots[i].first.first, c = robots[i].first.second;
                    if (r == ny && c == nx) {
                        collision_idx = to_string(i + 1);
                        break;
                    }
                }
                error_msg = "Robot " + robot_num + " crashes into robot " + collision_idx;
                flag = true;
                break;
            }
            map[y][x] = 0;
            map[ny][nx] = 1;
            y = ny;
            robots[robot_idx].first.first = y;
            break;
    }
}

int main() {
    scanf("%d %d", &a, &b);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x, y;
        char order;
        scanf("%d %d %c", &x, &y, &order);
        robots.push_back(make_pair(make_pair(b - y + 1, x), order));
        map[b - y + 1][x] = 1;  // 문제에서 설명하는 좌표 값은 행만 바뀌어서 들어감
    }

    for (int i = 0; i < m; ++i) {
        int robot_idx, order_count;
        char order;
        scanf("%d %c %d", &robot_idx, &order, &order_count);
        while (order_count--) {
            error_msg = "";
            flag = false;
            switch (order) {
                case 'L':
                    l_order(robot_idx - 1);
                    break;
                case 'R':
                    r_order(robot_idx - 1);
                    break;
                case 'F':
                    f_order(robot_idx - 1);
                    break;
            }
            if (flag) {
                printf("%s", error_msg.c_str());
                return 0;
            }
        }
    }

    if (!flag) {
        printf("OK");
        return 0;
    }

    return 0;
}