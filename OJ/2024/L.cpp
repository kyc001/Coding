#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int monster_x, monster_y;
    cin >> monster_x >> monster_y;
    string s;
    cin >> s;

    int isaac_x = 0, isaac_y = 0;
    int laser_hits = 0;

    for (char c : s) {
        if (c == 'w') {
            isaac_y++;
        } else if (c == 'a') {
            isaac_x--;
        } else if (c == 's') {
            isaac_y--;
        } else if (c == 'd') {
            isaac_x++;
        } else if (c == '1') {
            // 激光向上
            if (isaac_x == monster_x && isaac_y < monster_y) {
                laser_hits++;
            }
        } else if (c == '2') {
            // 激光向下
            if (isaac_x == monster_x && isaac_y > monster_y) {
                laser_hits++;
            }
        } else if (c == '3') {
            // 激光向左
            if (isaac_y == monster_y && isaac_x > monster_x) {
                laser_hits++;
            }
        } else if (c == '4') {
            // 激光向右
            if (isaac_y == monster_y && isaac_x < monster_x) {
                laser_hits++;
            }
        }

        // 检查以撒是否撞到怪物
        if (isaac_x == monster_x && isaac_y == monster_y) {
            break;
        }
    }

    cout << laser_hits << endl;

    return 0;
}