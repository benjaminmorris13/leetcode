class Solution {
public:
    bool hasCycle(ListNode* head) {
        vector<ListNode*> addys{};
        if (head == nullptr) {
            return false;
        }
        else {
            ListNode* current = head;
            while (current != nullptr) {
                for (size_t i = 0; i < addys.size(); i++) {
                    if (addys[i] == current) {
                        return true;
                    }
                    else {
                        continue;
                    }
                }
                addys.push_back(current);
                current = current->next;
            }
            return false;
        }
    }
};
