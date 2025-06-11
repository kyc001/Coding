#include <bits/stdc++.h>
using namespace std;

class Rational
{
    int numerator;
    int denominator;

public:
    Rational(int num, int denom) : numerator(num), denominator(denom)
    {
        simplify();
    }
    Rational operator+(const Rational &other) const
    {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }
    Rational operator-(const Rational &other) const
    {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }
    Rational operator*(const Rational &other) const
    {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }
    Rational operator/(const Rational &other) const
    {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }
    void simplify()
    {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    friend ostream &operator<<(ostream &os, const Rational &r)
    {
        if (r.denominator == 1)
            os << r.numerator;
        else
            os << r.numerator << "/" << r.denominator;
        return os;
    }
};

int a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    Rational R1(a, b);
    cin >> a >> b;
    Rational R2(a, b);
    cout << R1 + R2 << endl;
    cout << R1 - R2 << endl;
    cout << R1 * R2 << endl;
    cout << R1 / R2 << endl;
    cout << R1 + Rational(1, 1) << " " << R2 + Rational(1, 1) << endl;
    cout << Rational(1, 1) / R1 << " " << Rational(1, 1) / R2;
    return 0;
}