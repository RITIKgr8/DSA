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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* result = head;
        int count =0;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        int i = count - n;
        if(i == 0){
            head = head->next;
            return head;
        }else{
            while(i>1){
                head = head->next;
                i--;
            }
            head->next = head->next->next;
            return result;
        }
    }
};