//��������� 
class complex {
public:
	complex (const complex & c) {
		
	} ;
	double r, i;
	friend istream &operator >> (istream &in, complex &com) {
		in >> com.r >> com.i;
		return in;
	}
	friend ostream &operator << (ostream &out, const complex &com) {
		cout << com.r << ' ' << com.i;
		return out;
	}
};


ǰ�������
��Ա���� 
T & operator ++();
ȫ�ֺ���
T1 &operator ++(T2);

���������
��Ա����
T & operator ++(int);
ȫ�ֺ���
T1 operator ++(T2, int); 

ȫ��
// ǰ��++
Counter& operator++(Counter& c) {
    ++c.value;
    return c;
}

// ����++
Counter operator++(Counter& c, int) {
    Counter temp = c;
    ++c;
    return temp;
} 





//�麯�� 
virtual ~function() = default;
virtual int function(int x) const = 0;


//��������� 
friend Counter& operator++(Counter& c);      // ǰ��++
friend Counter operator++(Counter& c, int);  // ����++



template <typename T, int i> class TestClass {
  public:
     T buffer[i];  
//T���͵�buffer�����С����ͨ�β�i��ֵ�仯
     T getData(int j);  
};?
template <typename T, int i>  
T TestClass<T,i>::getData(int j) {
    return *(buffer+j);    
}; 


// ��������͵���GtLever�ĺ���ģ��
template <class T>
void processInput(int length, int n) {
    unique_ptr<T[]> arr(new T[length]);  // ʹ������ָ������ڴ�
    for(int i = 0; i < length; i ++) {
        cin >> arr[i];
    }
    T lever;
    cin >> lever;
    GtLever(arr.get(), n, lever);
}
//���췽�� 
processInput<char>(length, n);

std::unique_ptr<T[]> a;  // ʹ������ָ������ڴ�

public:
    // ���캯��
    C1(int n) : num(n), a(std::make_unique<T[]>(n)) {}



