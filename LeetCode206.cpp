class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        else if (head->next == nullptr) {
            return head;
        }
        else {
            ListNode* current = head;
            ListNode* prev = nullptr;
            ListNode* next = current->next;
            current->next = prev;
            while (next != nullptr) {
                prev = current;
                current = next;
                next = current->next;
                current->next = prev;
            }
            return current;
        }
    }
};
