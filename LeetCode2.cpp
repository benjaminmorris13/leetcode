/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if ((l1 == nullptr) && (l2 == nullptr)) {
            return nullptr;
        }
        else if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            if (l1->val < 10) {
                return l1;
            }
            else {
                if (l1->next == nullptr) {
                    l1->next = new ListNode(1);
                }
                else {
                    l1->next->val += 1;
                }
                l1->val = l1->val - 10;
                ListNode* result = new ListNode(l1->val);
                result->next = addTwoNumbers(l1->next, l2);
                return result;
            }
        }
        else {
            int sum = l1->val + l2->val;
            if (sum > 9) {
                if (l1->next == nullptr) {
                    l1->next = new ListNode(1);
                }
                else {
                    l1->next->val += 1;
                }
                sum -= 10;
            }
            else {
                sum += 0;
            }
            ListNode* result = new ListNode(sum);
            result->next = addTwoNumbers(l1->next, l2->next);
            return result;
        }
    }
};
