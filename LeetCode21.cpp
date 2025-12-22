class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!(list1) && (list2)) {
            return list2;
        }
        else if (!(list2) && (list1)) {
            return list1;
        }
        else if (!(list2) && !(list1)) {
            return nullptr;
        }
        else {
            ListNode* head;
            ListNode* current;
            ListNode* current1 = list1;
            ListNode* current2 = list2;
            if (list1->val < list2->val) {
                head = list1;
                current = list1;
                current1 = current1->next;
            }
            else if (list2->val < list1->val) {
                head = list2;
                current = list2;
                current2 = current2->next;
            }
            else {
                head = list1;
                current1 = current1->next;
                head->next = list2;
                current2 = current2->next;
                current = head->next;
            }
            while ((current1 != nullptr) && (current2 != nullptr)) {
                if (current1->val < current2->val) {
                    current->next = current1;
                    current = current->next;
                    current1 = current1->next;
                }
                else if (current2->val < current1->val) {
                    current->next = current2;
                    current = current->next;
                    current2 = current2->next;
                }
                else {
                    current->next = current1;
                    current = current->next;
                    current1 = current1->next;
                    current->next = current2;
                    current = current->next;
                    current2 = current2->next;
                }
            }
            if ((current1 == nullptr) && (current2 != nullptr)) {
                current->next = current2;
            }
            else if ((current2 == nullptr) && (current1 != nullptr)) {
                current->next = current1;
            }
            else {
                return head;
            }
            return head;
        }
    }
};
