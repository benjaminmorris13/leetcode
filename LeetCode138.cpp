/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        else {
            unordered_map<Node*, Node*> trans;
            Node* current = head;
            Node* now = new Node(current->val);
            now->random = current->random;
            trans[current] = now;
            Node* result = now;
            current = current->next;
            while (current != nullptr) {
                now->next = new Node(current->val);
                now->next->random = current->random;
                now = now->next;
                trans[current] = now;
                current = current->next;
            }
            Node* loco = result;
            Node* update;
            while (loco != nullptr) {
                if (loco->random == nullptr) {
                    loco = loco->next;
                }
                else {
                    update = trans[loco->random];
                    loco->random = update;
                    loco = loco->next;
                }
            }  
            return result;
        }
    }
};
