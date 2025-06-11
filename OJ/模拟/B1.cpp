#include<bits/stdc++.h>
using namespace std;

class Complex {
public:
	double real, imag;
	Complex(double r, double i) : real(r), imag(i){};
	Complex operator- (const Complex &b) {
		Complex c(0,0);
		c.real = real - b.real;
		c.imag = imag - b.imag;
		return c;
	}
	Complex operator+ (const Complex &b) {
		Complex c(0,0);
		c.real = real + b.real;
		c.imag = imag + b.imag;
		return c;
	}
friend ostream &operator<< (ostream& out, const Complex &b) {
    if(b.real == 0 && b.imag == 0) {
        out << "0";
        return out;
    }
    
    if(b.real != 0) {
        out << fixed << setprecision(2) << b.real;
        if(b.imag > 0) 
            out << '+';
        else if(b.imag < 0)
            out << "";  // ���Ż������b.imag��
    }
    
    if(b.imag != 0) {
        if(b.real == 0)  // ���ʵ��Ϊ0��ֱ������鲿
            out << fixed << setprecision(2) << b.imag << 'i';
        else  // ���ʵ����Ϊ0��ǰ���Ѿ������˷���
            out << fixed << setprecision(2) << b.imag << 'i';
    }
    
    return out;
}
};

double r, i;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> i;
	Complex c1(r, i);
	cin >> r >> i;
	Complex c2(r, i);
	cout << c1+c2 << endl;
	cout << c1-c2 << endl;
	return 0;
}



