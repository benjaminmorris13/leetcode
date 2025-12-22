class Solution {
public:
    ListNode* at(ListNode* head, int index) {
        ListNode* current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        return current;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if ((right - left) % 2 == 0) {
            while (left != right) {
                int albert = at(head, left)->val;
                at(head, left)->val = at(head, right)->val;
                at(head, right)->val = albert;
                left = left + 1;
                right = right - 1;
            }
        }
        else {
            while (left < right) {
                int einstein = at(head, left)->val;
                at(head, left)->val = at(head, right)->val;
                at(head, right)->val = einstein;
                left = left + 1;
                right = right - 1;
            }
        }
        return head;
    }
};
