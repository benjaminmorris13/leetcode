class Solution {
public:
    int length(ListNode* head) {
        ListNode* current = head;
        int counter = 0;
        while (current != nullptr) {
            counter = counter + 1;
            current = current->next;
        }
        return counter;
    }
    ListNode* at(ListNode* head, int index) {
    ListNode* current = head;
    for (int i = 1; i < index; i++) {
        current = current->next;
    }
    return current;
    }
    void reorderList(ListNode* head) {
        int syze = length(head);
        int counter = length(head);
        int ogcounter = 2;
        ListNode* current = head;
        ListNode* albert = head->next;
        if (counter <= 1) {
            return;
        }
        else {
            ListNode* einstein = at(head, counter);
            while (ogcounter < counter) {
                current->next = einstein;
                current = current->next;
                current->next = albert;
                current = current->next;
                albert = current->next;
                counter = counter - 1;
                ogcounter = ogcounter + 1;
                einstein = at(head, syze);
            }
            if (ogcounter == counter) {
                current->next->next = nullptr;
            }
            else {
                current->next = nullptr;
            }
        }
    }
};
