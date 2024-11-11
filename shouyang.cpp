#include <iostream>
using namespace std;

// 结构体adoption用于表示收容所中的动物信息
struct adoption {
    int x;  // 动物编号，正数表示狗，负数表示猫
    int nextt;  // 用于构建按进入顺序的链表
    int next1; // 用于构建同类动物的链表（狗或猫）
    int last;  // 用于构建按进入顺序的链表，指向前一个动物
} pet[500];

int m;  // 用于接收输入的操作类型
int cnt = 0;  // 记录当前收容所中动物的数量
int ne;  // 暂未明确具体用途，可先保留
int nh = 0;  // 猫链表头指针，初始为0
int yh = 0;  // 狗链表头指针，初始为0
int nt;  // 暂未明确具体用途，可先保留
int yt;  // 暂未明确具体用途，可先保留
int h = 0;  // 整个收容所动物链表的头指针（按进入顺序）
int t = 0;  // 整个收容所动物链表的尾指针（按进入顺序）

int main() {
    while (cin >> m) {
        if (m == 1) {
            // 有动物进入收容所
            int num; 
			cin >> num; 
			if(num > 100 || num < -100) continue;
			cnt++;
            if (!h) h = cnt;
            pet[t].nextt = cnt;
            pet[cnt].last = t;
            t = cnt;
            
            if (num < 0) {
                // 进入的是猫
                pet[cnt].x = num;
                if (!nh) nh = cnt;
                pet[nt].next1 = cnt;
                nt = cnt;
            } 
			if(num>0){
                // 进入的是狗
                pet[cnt].x = num;
                if (!yh) yh = cnt;
                pet[yt].next1 = cnt;
                yt = cnt;
            }
        } if(m==2) {
            // 有人收养动物
            int way;
            cin >> way;

            if (way == 0) {
                // 收养最早进入收容所的动物
                if (h == 0) continue;

                cout << pet[h].x << " ";

                if (pet[h].x > 0) {
                    yh = pet[h].next1;
                } else if (pet[h].x < 0) {
                    nh = pet[h].next1;
                }

                if (h == t) {
                    // 如果只剩这一只动物，重置头指针和尾指针
                    h = 0;
                    t = 0;
                } else {
                    h = pet[h].nextt;
                    pet[h].last = 0;
                }
            } else if (way == 1) {
                // 指定收养狗
                if (yh == 0) continue;

                cout << pet[yh].x << " ";

                if (h == yh) {
                    // 如果收养的狗刚好是当前头指针指向的动物
                    if (yh == t) {
                        // 如果只剩这一只狗，重置头指针和尾指针
                        h = 0;
                        t = 0;
                    } else {
                        h = pet[yh].nextt;
                        pet[h].last = 0;
                    }
                } else {
                    // 调整狗链表指针关系
                    if (pet[yh].last) {
                        pet[pet[yh].last].nextt = pet[yh].nextt;
                    }
                    if (pet[yh].nextt) {
                        pet[pet[yh].nextt].last = pet[yh].last;
                    }
                }

                yh = pet[yh].next1;
            } else if (way == -1) {
                // 指定收养猫
                if (nh == 0) continue;

                cout << pet[nh].x << " ";

                if (h == nh) {
                    // 如果收养的猫刚好是使当前头指针指向的动物
                    if (nh == t) {
                        // 如果只剩这一只猫，重置头指针和尾指针
                        h = 0;
                        t = 0;
                    } else {
                    h = pet[nh].nextt;
                    pet[h].last = 0;
                    }
                } else {
                    // 调整猫链表指针关系
                    if (pet[nh].last) {
                        pet[pet[nh].last].nextt = pet[nh].nextt;
                    }
                    if (pet[nh].nextt) {
                        pet[pet[nh].nextt].last = pet[nh].last;
                    }
                }

                nh = pet[nh].next1;
            }
        }
    }

    return 0;
}
