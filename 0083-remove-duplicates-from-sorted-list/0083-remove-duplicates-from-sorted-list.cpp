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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* check = head->next;
        ListNode* temp = head;
        while(check != nullptr){
            if(check->val != temp->val){
                temp->next = check;
                temp = temp->next;
                check = check->next;
            }else{
                check = check->next;
                temp->next = check;
            }
        }
        return head;
    }
};