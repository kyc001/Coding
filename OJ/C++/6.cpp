#include <bits/stdc++.h>
using namespace std;

// ˫������ڵ�ṹ��
struct Node {
    int val;            // ����ID
    Node* prev;         // ǰ���ڵ�
    Node* next;         // ��̽ڵ�
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// �����б������
class ChatManager {
private:
    unordered_map<int, Node*> map;  // ��ϣ��ID���ڵ��ӳ��
    Node* head;                     // ����ͷ�����½ڵ㣩
    Node* tail;                     // ����β����ɽڵ㣩

public:
    ChatManager() {
        head = tail = nullptr;
    }

    // ���ڵ��ƶ�������ͷ��
    void moveToHead(Node* node) {
        if (node == head) return;  // �Ѿ���ͷ���������
        
        // �Ͽ���ǰ�ڵ��ǰ������
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        
        // ����ڵ���β�ڵ㣬����β�ڵ�
        if (node == tail) tail = node->prev;
        
        // ���뵽ͷ��
        node->prev = nullptr;
        node->next = head;
        if (head) head->prev = node;
        head = node;
        
        // ���ԭ������Ϊ�գ������β�ڵ�Ҳ�Ǹýڵ�
        if (!tail) tail = head;
    }

    // ����½ڵ㵽ͷ��
    void addNewToHead(int val) {
        Node* newNode = new Node(val);
        map[val] = newNode;
        
        if (!head) {  // ������
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // ����һ����Ϣ
    void processMessage(int id) {
        if (map.count(id)) {  // ID���ڣ��ƶ���ͷ��
            moveToHead(map[id]);
        } else {  // ID�����ڣ�������ͷ��
            addNewToHead(id);
        }
    }

    // ��ȡ��ǰ�б�˳�򣨴�ͷ����β����
    vector<int> getList() {
        vector<int> res;
        Node* curr = head;
        while (curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }

    // �ͷ��ڴ棨��ֹ�ڴ�й©��
    ~ChatManager() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int T;
        cin >> T;
        ChatManager cm;
        for (int j = 0; j < T; ++j) {
            int id;
            cin >> id;
            cm.processMessage(id);
        }
        vector<int> list = cm.getList();
        for (size_t k = 0; k < list.size(); ++k) {
            cout << list[k];
            if (k != list.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
