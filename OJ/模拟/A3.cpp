//#include<bits/stdc++.h>
//using namespace std;
//template<typename T>
//class mystack{
//public:
//	T *p;
//	int num=0;
//	mystack() {
//		p = new T[1000];
//	}
//	~mystack() {
//		delete []p;
//	}
//	void push(T t) {
//		p[num ++] = t;
//	}
//	void pop() {
//		if(isempty()) return;
//		num --;
//	}
//	bool isempty() {
//		return num == 0;
//	}
//	void show() {
//		for(int i = num - 1; i >= 0; i --) {
//			cout << p[i] << ' ';
//		} 
//		cout << endl;
//	}
//};
//char op;
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	mystack<int> s1;
//	while(scanf("%c", &op)) {
//		if(op == '\n') break;
//		if(op == 'i') {
//			int temp;
//			cin >> temp;
//			s1.push(temp);
//		}
//		else if(op == 'o') {
//			s1.pop();
//		}
//		else if(op == 's') {
//			s1.show();
//		}
//	}
//	mystack<char> s2;
//	while(cin >> op) {
//		if(op == 'i') {
//			char temp;
//			cin >> temp;
//			s2.push(temp);
//		}
//		else if(op == 'o') {
//			s2.pop();
//		}
//		else if(op == 's') {
//			s2.show();
//		}
//	}
//
//	return 0;
//}
//
//
#include <iostream>
#include <string>
#include <sstream> // ���ڽ����ַ�����

// ����һ��������Ϊջ��Ĭ������
const int STACK_CAPACITY = 100;

/**
 * @brief ͨ��ջ��ģ��
 * @tparam T ջ�д洢����������
 */
template <class T>
class MyStack {
private:
    T* data;       // ʹ��ָ��ָ��̬��������飬���ڴ洢ջԪ��
    int top_index; // ջ��Ԫ�ص�������-1��ʾջ��
    int capacity;  // ջ������

public:
    // ���캯��������ָ������
    MyStack(int size = STACK_CAPACITY);
    // �����������ͷŶ�̬������ڴ�
    ~MyStack();

    // ��Ա����
    void push(T value); // ��ջ
    void pop();         // ��ջ
    bool isEmpty();     // �ж�ջ�Ƿ�Ϊ��
    void show();        // ��ʾջ������Ԫ��
};

/**
 * @brief ���캯��
 * @tparam T
 * @param size ջ������
 */
template <class T>
MyStack<T>::MyStack(int size) {
    capacity = size;
    data = new T[capacity]; // ��̬�����ڴ�
    top_index = -1;         // ��ʼ��ջ����������ʾջ��
}

/**
 * @brief ��������
 * @tparam T
 */
template <class T>
MyStack<T>::~MyStack() {
    delete[] data; // �ͷŶ�̬����������ڴ�
    data = 0;
}

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 * @tparam T
 * @return ���ջΪ���򷵻�true�����򷵻�false
 */
template <class T>
bool MyStack<T>::isEmpty() {
    return top_index == -1;
}

/**
 * @brief ��ջ����
 * @tparam T
 * @param value Ҫ��ջ��Ԫ��
 */
template <class T>
void MyStack<T>::push(T value) {
    // ��Ŀ��֤����ջ��������ʵ�ʹ�����Ӧ��� top_index < capacity - 1
    top_index++;
    data[top_index] = value;
}

/**
 * @brief ��ջ����
 * @tparam T
 */
template <class T>
void MyStack<T>::pop() {
    if (isEmpty()) {
        // ������ĿҪ�����ջ������� "Empty"
        std::cout << "Empty" << std::endl;
        return;
    }
    top_index--; // ���ƶ�ջ��ָ�룬��ʵ���������
}

/**
 * @brief ��ʾջ������Ԫ�أ���ջ����ջ�ף�
 * @tparam T
 */
template <class T>
void MyStack<T>::show() {
    if (isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    // ��ջ����ʼ������ֱ��ջ��
    for (int i = top_index; i >= 0; --i) {
        std::cout << data[i] << (i == 0 ? "" : " "); // ���һ��Ԫ�غ󲻼ӿո�
    }
    std::cout << std::endl;
}

/**
 * @brief ����һ�в���ָ���ͨ�ú���
 * @tparam T ջ���������� (int �� char)
 * @param stack Ҫ������ջ����
 * @param line ��������ָ����ַ���
 */
template <typename T>
void process_operations(MyStack<T>& stack, const std::string& line) {
    std::stringstream ss(line); // �����ַ������Է���ؽ����ַ���
    char operation_code;
    T value;

    // �����ȡ������
    while (ss >> operation_code) {
        switch (operation_code) {
            case 'i': // ��ջ����
                ss >> value; // ��ȡҪ��ջ��Ԫ��
                stack.push(value);
                break;
            case 'o': // ��ջ����
                stack.pop();
                break;
            case 's': // ��ʾ����
                stack.show();
                break;
        }
    }
}

int main() {
    // ���C++����IOЧ��
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;

    // --- �����һ�У�����ջ ---
    if (getline(std::cin, line)) {
        MyStack<int> int_stack;
        process_operations(int_stack, line);
    }

    // --- ����ڶ��У��ַ�ջ ---
    if (getline(std::cin, line)) {
        MyStack<char> char_stack;
        process_operations(char_stack, line);
    }

    return 0;
}

