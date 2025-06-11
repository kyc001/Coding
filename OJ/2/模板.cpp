#include<bits/stdc++.h>
using namespace std;
class Student {
    private:
        int num;
        string name;
        int score;
    public:
        Student() : num(0), name(""), score(0) {}
        friend istream& operator >> (istream &in, Student &s) {
            in>>s.num>>s.name>>s.score;
            return in;
        }
        friend ostream& operator << (ostream &out, Student &s) {
            out<<s.num;
            return out;
        }
        bool operator < (const Student &s) const{
            return score < s.score;
        }
};
template <typename T>
class Array {
    private:
        int size;
        T* element;
    public:
        Array(int n) : size(n) {
            element = new T[size];
        }
        ~Array() {
            delete[] element;
        }
        friend istream& operator >> (istream &in, Array &a) {
            for(int i = 0; i < a.size; i ++)
                in>>a.element[i];
            return in;
        }
        friend ostream& operator << (ostream &out, Array &a) {
            for(int i = 0; i < a.size; i ++)
                out<<a.element[i]<<" ";
            return out;
        }
        void sort() {
            std::sort(element, element + size);
        }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    // int 类型
    Array<int> array_int(N);
    cin >> array_int;
    array_int.sort();
    cout << array_int << endl;

    // double 类型
    Array<double> array_double(N);
    cin >> array_double;
    array_double.sort();
    cout << array_double << endl;

    // char 类型
    Array<char> array_char(N);
    cin >> array_char;
    array_char.sort();
    cout << array_char << endl;

    // Student 类型
    Array<Student> array_student(N);
    cin >> array_student;
    array_student.sort();
    cout << array_student << endl;

    return 0;
}