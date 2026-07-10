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
        ListNode dummy;
        ListNode* sum = &dummy;
        int carry =0;
        while(l1 != nullptr || l2 != nullptr || carry !=0){
            int add = carry;
            if(l1 != nullptr){
                add = add + l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                add = add + l2->val;
                l2 = l2->next;
            }

            sum->next = new ListNode(add%10);
            sum = sum->next;
            carry = add/10;
        }
        return dummy.next;
    }
};