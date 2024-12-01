#include<bits/stdc++.h>
using namespace std;
template<typename T>
class MyLinkedStack {
    private:
        list<T> list;
    public:
        
        void push(const T& element) {
            list.push_back(element);
        }

        T pop() {
            T value = list.back();
            list.pop_back();
            return value;
        }

        T peek() const {
            return list.back();
        }

        int size() const {
            return list.size();
        }

};
MyLinkedStack<int> Stack;
int main() {
    Stack.push(1);
    Stack.push(2);
    Stack.push(3);
    Stack.push(4);
    while(Stack.size() > 0) {
        cout << Stack.pop() << endl;
    }
    return 0;
}