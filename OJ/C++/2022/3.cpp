#include<bits/stdc++.h>
#define nullptr NULL
using namespace std;

template<typename T>
class List {
    struct node {
        T data;
        node* next;
    } *head, *tail;

public: 
    List() : head(nullptr), tail(nullptr) {}
    
    ~List() {  // ������������ͷ��ڴ�
        clear();
    }
    
    void Insert(const T& item) {
        node* newNode = new node();
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;  // ������������
    }
    
    void Append(const T& item) {
        node* newNode = new node();
		newNode->data = item;
		newNode->next = NULL; 
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int count() const {
        if(!head) return 0;
        node *p = head;
        int res;
        while(p->next) {
        	res ++;
        	p = p->next;
		}
		res ++;
		return res;
    }
    
    void htot() {  // ͷ�ڵ��Ƶ�β��
        if (!head || head == tail) return;
        node* temp = head;
        head = head->next;
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
    }
    
    void ttoh() {  // β�ڵ��Ƶ�ͷ��
        if (!head || head == tail) return;
        node* prev = nullptr;
        node* curr = head;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        curr->next = head;
        head = curr;
    }
    
    void display() const {
        if (!head) {
            cout << "emptyList" << endl;
            return;
        }
        node* temp = head;
        while (temp) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
    
    void clear() {  // ����������ķ���
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }
    
    void SortList() {  // ��ʵ�ֵ����򷽷�
        if (!head || head == tail) return;
		int *p = nullptr, len = count(), num=0;
		p = new int[len];
        node* temp = head;
        while (temp) {
            p[num ++] = temp->data;
            temp = temp->next;
        }
        sort(p, p + num);
        clear();
        for (int i = 0; i < num; i ++) {
            Append(p[i]);
        }
    }
};

int main() {
    string s;
    int n, t;
    cin >> s >> n;
    if (s[0] == 'i') {
        List<int> l1, l2;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            l1.Append(t);
            l2.Insert(t);
        }
        cout << l1.count() << endl;
   		l1.display();
   		l1.ttoh();l1.display();
		cout << l2.count() << endl;
		l2.display();
		l2.htot();l2.display();
		l1.SortList();l2.display(); 
    }
	else if (s[0] == 'c') {  // �����ַ�����
        List<char> l1, l2;
        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            l1.Append(c);
            l2.Insert(c);
        }
        cout << l1.count() << endl;
		l1.display();
    	l1.ttoh();l1.display();
		cout << l2.count() << endl;
		l2.display();
		l2.htot();l2.display();
		l1.SortList();l2.display(); 
    }

    return 0;
}
/*
int
5
5 2 3 4 1
*/
