//重载运算符 
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


前置运算符
成员函数 
T & operator ++();
全局函数
T1 &operator ++(T2);

后置运算符
成员函数
T & operator ++(int);
全局函数
T1 operator ++(T2, int); 

全局
// 前置++
Counter& operator++(Counter& c) {
    ++c.value;
    return c;
}

// 后置++
Counter operator++(Counter& c, int) {
    Counter temp = c;
    ++c;
    return temp;
} 





//虚函数 
virtual ~function() = default;
virtual int function(int x) const = 0;


//重载运算符 
friend Counter& operator++(Counter& c);      // 前置++
friend Counter operator++(Counter& c, int);  // 后置++



template <typename T, int i> class TestClass {
  public:
     T buffer[i];  
//T类型的buffer，其大小随普通形参i的值变化
     T getData(int j);  
};?
template <typename T, int i>  
T TestClass<T,i>::getData(int j) {
    return *(buffer+j);    
}; 


// 处理输入和调用GtLever的函数模板
template <class T>
void processInput(int length, int n) {
    unique_ptr<T[]> arr(new T[length]);  // 使用智能指针管理内存
    for(int i = 0; i < length; i ++) {
        cin >> arr[i];
    }
    T lever;
    cin >> lever;
    GtLever(arr.get(), n, lever);
}
//构造方法 
processInput<char>(length, n);

std::unique_ptr<T[]> a;  // 使用智能指针管理内存

public:
    // 构造函数
    C1(int n) : num(n), a(std::make_unique<T[]>(n)) {}



