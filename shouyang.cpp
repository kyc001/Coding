#include <iostream>
using namespace std;

// �ṹ��adoption���ڱ�ʾ�������еĶ�����Ϣ
struct adoption {
    int x;  // �����ţ�������ʾ����������ʾè
    int nextt;  // ���ڹ���������˳�������
    int next1; // ���ڹ���ͬ�ද�����������è��
    int last;  // ���ڹ���������˳�������ָ��ǰһ������
} pet[500];

int m;  // ���ڽ�������Ĳ�������
int cnt = 0;  // ��¼��ǰ�������ж��������
int ne;  // ��δ��ȷ������;�����ȱ���
int nh = 0;  // è����ͷָ�룬��ʼΪ0
int yh = 0;  // ������ͷָ�룬��ʼΪ0
int nt;  // ��δ��ȷ������;�����ȱ���
int yt;  // ��δ��ȷ������;�����ȱ���
int h = 0;  // �������������������ͷָ�루������˳��
int t = 0;  // �������������������βָ�루������˳��

int main() {
    while (cin >> m) {
        if (m == 1) {
            // �ж������������
            int num; 
			cin >> num; 
			if(num > 100 || num < -100) continue;
			cnt++;
            if (!h) h = cnt;
            pet[t].nextt = cnt;
            pet[cnt].last = t;
            t = cnt;
            
            if (num < 0) {
                // �������è
                pet[cnt].x = num;
                if (!nh) nh = cnt;
                pet[nt].next1 = cnt;
                nt = cnt;
            } 
			if(num>0){
                // ������ǹ�
                pet[cnt].x = num;
                if (!yh) yh = cnt;
                pet[yt].next1 = cnt;
                yt = cnt;
            }
        } if(m==2) {
            // ������������
            int way;
            cin >> way;

            if (way == 0) {
                // ������������������Ķ���
                if (h == 0) continue;

                cout << pet[h].x << " ";

                if (pet[h].x > 0) {
                    yh = pet[h].next1;
                } else if (pet[h].x < 0) {
                    nh = pet[h].next1;
                }

                if (h == t) {
                    // ���ֻʣ��һֻ�������ͷָ���βָ��
                    h = 0;
                    t = 0;
                } else {
                    h = pet[h].nextt;
                    pet[h].last = 0;
                }
            } else if (way == 1) {
                // ָ��������
                if (yh == 0) continue;

                cout << pet[yh].x << " ";

                if (h == yh) {
                    // ��������Ĺ��պ��ǵ�ǰͷָ��ָ��Ķ���
                    if (yh == t) {
                        // ���ֻʣ��һֻ��������ͷָ���βָ��
                        h = 0;
                        t = 0;
                    } else {
                        h = pet[yh].nextt;
                        pet[h].last = 0;
                    }
                } else {
                    // ����������ָ���ϵ
                    if (pet[yh].last) {
                        pet[pet[yh].last].nextt = pet[yh].nextt;
                    }
                    if (pet[yh].nextt) {
                        pet[pet[yh].nextt].last = pet[yh].last;
                    }
                }

                yh = pet[yh].next1;
            } else if (way == -1) {
                // ָ������è
                if (nh == 0) continue;

                cout << pet[nh].x << " ";

                if (h == nh) {
                    // ���������è�պ���ʹ��ǰͷָ��ָ��Ķ���
                    if (nh == t) {
                        // ���ֻʣ��һֻè������ͷָ���βָ��
                        h = 0;
                        t = 0;
                    } else {
                    h = pet[nh].nextt;
                    pet[h].last = 0;
                    }
                } else {
                    // ����è����ָ���ϵ
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
