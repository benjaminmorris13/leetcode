class MyLinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int value, Node* pre=nullptr, Node* post=nullptr) : val{value}, prev{pre}, next{post} {};
    };
    Node head;
    Node tail;
    int size;
public:
    MyLinkedList() :  head{Node(1001)}, tail{Node(1001)}, size{0}{
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        else {
            Node* current = &head;
            for (int i = 0; i <= index; i++) {
                current = current->next;
            }
            return current->val;
        }
    }
    
    void addAtHead(int val) {
        Node* albert = head.next;
        Node* fish = new Node(val, &head, albert);
        head.next = fish;
        albert->prev = head.next;
        size += 1;
    }
    
    void addAtTail(int val) {
        Node* albert = tail.prev;
        Node* fish = new Node(val, albert, &tail);
        tail.prev = fish;
        albert->next = tail.prev;
        size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        else if (index == size) {
            addAtTail(val);
        }
        else {
            Node* right = &head;
            for (int i = 0; i <= index; i++) {
                right = right->next;
            }
            Node* left = right->prev;
            Node* fish = new Node(val, left, right);
            left->next = fish;
            right->prev = left->next;
            size += 1;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        else {
            Node* abort = &head;
            for (int i = 0; i <= index; i++) {
                abort = abort->next;
            }
            Node* left = abort->prev;
            Node* right = abort->next;
            left->next = right;
            right->prev = left;
            delete abort;
            size -= 1;
        }
    }
};
