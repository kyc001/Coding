#include<bits/stdc++.h>
using namespace std;

template <typename E>
class MyLinkedQueue {
    private:
        list<E> list;
    public:
        void push(const E &e) {
            list.push_back(e);
        }
        E pop() {
            E front = list.front();
            list.pop_front();
            return front;
        }
        E peek() {
            return list.front();
        }
        int size() {
            return list.size();
        }
};
MyLinkedQueue<int> Queue;
int main() {
    Queue.push(1);
    Queue.push(2);
    Queue.push(3); 
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    cout << Queue.pop() << endl;
    return 0;
}