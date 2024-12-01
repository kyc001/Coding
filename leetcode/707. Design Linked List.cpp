class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int value) : val(value), next(nullptr), prev(nullptr){}
    };
    private: 
        int size;
        Node* head;
        Node* tail;
    public:
        MyLinkedList() {
            this -> size = 0;
            this -> head = new Node(int());
            this -> tail = new Node(int());
            head -> next = tail;
            tail -> prev = head;
        }
        
        int get(int index) {
            if(index < 0 || index >= size) {
                return -1;
            }
            Node* cur = head;
            for(int i = 0; i <= index; i++) {
                cur = cur -> next;
            }
            return cur -> val;
        }
        
        void addAtHead(int val) {
            addAtIndex(0, val);
        }
        
        void addAtTail(int val) {
            addAtIndex(size, val);
        }
        
        void addAtIndex(int index, int val) {
            if(index > size) {
                return;
            }
            index = max(index, 0);
            Node* cur = head;
            for(int i = 0; i < index; i ++) {
                cur = cur -> next;
            }
            Node* newNode = new Node(val);
            newNode -> next = cur -> next;
            newNode -> next -> prev = newNode;
            cur -> next = newNode;
            newNode -> prev = cur;
            size++;
        }
        
        void deleteAtIndex(int index) {
            if (index < 0 || index >= size) {
                return;
            }
            Node* cur = head;
            for(int i = 0; i <= index; i ++) {
                cur = cur -> next;
            }
            cur -> prev -> next = cur -> next;
            cur -> next -> prev = cur -> prev;
            delete cur;
            size--;
        }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */