class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* before;
        ListNode* after;
        ListNode* current = head;
        int counter = 0;
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        while (current != nullptr) {
            current = current->next;
            counter = counter + 1;
        }
        if (counter == 2) {
            if (n == 1) {
                delete head->next;
                head->next = nullptr;
                return head;
            }
            else {
                ListNode* dummy = head;
                head = head->next;
                delete dummy;
                return head;
            }
        }
        if (n == counter) {
            ListNode* gates = head;
            head = head->next;
            delete gates;
            return head;
        }
        current = head;
        int index = 1;
        while (current != nullptr) {
            if (index == counter - n) {
                before = current;
                current = current->next;
                index = index + 1;
            }
            else {
                current = current->next;
                index = index + 1;
            }
        }
        after = before->next;
        before->next = before->next->next;
        delete after;
        return head;
    }
};
