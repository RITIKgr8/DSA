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
    void reorderList(ListNode* head) {
        // for empty or single value lists
        if(head == nullptr || head->next == nullptr){
            return ;
        }
        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // now split two lists
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* first = head;
        // reverse second
        ListNode* curr = second;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* reversed = prev;
        // now merge
        while(first != nullptr && reversed != nullptr){
            ListNode* temp1 = first->next;
            first->next = reversed;
            ListNode* temp2 = reversed->next;
            reversed->next = temp1;
            first = temp1;
            reversed = temp2;
        }
    }
};