#include<bits/stdc++.h>
using namespace std;

// ���ࣺDistance
class Distance {
protected:
    int x1, y1, x2, y2;
public:
    Distance(int x1, int y1, int x2, int y2) 
        : x1(x1), y1(y1), x2(x2), y2(y2) {}
    
    // ���麯�����������
    virtual int calculate() const = 0;
    
    // ����������ȷ����ȷ�ͷ����������
    virtual ~Distance() {}
};

// �����ࣺ�����پ���
class ManhattanDistance : public Distance {
public:
    ManhattanDistance(int x1, int y1, int x2, int y2) 
        : Distance(x1, y1, x2, y2) {}
    
    int calculate() const override {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};

// �����ࣺŷ����þ����ƽ��
class EuclideanDistance : public Distance {
public:
    EuclideanDistance(int x1, int y1, int x2, int y2) 
        : Distance(x1, y1, x2, y2) {}
    
    int calculate() const override {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    // ʹ�û���ָ��ָ��̬��������������
    Distance* manhattan = new ManhattanDistance(x1, y1, x2, y2);
    Distance* euclidean = new EuclideanDistance(x1, y1, x2, y2);
    
    // ͨ������ָ������麯��ʵ�ֶ�̬����
    cout << manhattan->calculate() << " " << euclidean->calculate() << endl;
    
    // �ֶ��ͷ��ڴ棬��ֹ�ڴ�й©
    delete manhattan;
    delete euclidean;
    
    return 0;
}
