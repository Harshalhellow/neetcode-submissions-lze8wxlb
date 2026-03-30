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
        ListNode* curr1 = l1;
        int count1 = 0;
        while(curr1!=nullptr){
            curr1 = curr1->next; 
            count1++; 
        }
        ListNode* curr2 = l2;
        int count2 = 0;
        while(curr2!=nullptr){
            curr2 = curr2->next; 
            count2++; 
        }
        ListNode* l1s = nullptr; 
        ListNode* l2s = nullptr; 
        if(count1>=count2){
            l1s = l1; 
            l2s = l2; 
        }
        else{
            l1s = l2; 
            l2s = l1; 
        }
        ListNode* head = l1s;

        int sum = 0; 
        int carry = 0;
        ListNode*l1Stail = nullptr; 
        while(l2s!=nullptr){
            if(carry>0) l1s->val++; 
            carry = 0; 
            sum = l1s->val + l2s->val;
            if(sum>=10){
                sum -=10;
                carry++;
            }
            l1s->val = sum; 
            l1Stail = l1s;
            l1s = l1s->next;
            l2s = l2s->next;
        }
        
        while(carry>0&&l1Stail->next!=nullptr){
            l1Stail = l1Stail->next;
            sum = l1Stail->val+ carry; 
            if(sum>=10){
                sum -=10;
                l1Stail->val = sum; 
            }
            else {
                carry = 0;
                l1Stail->val = sum;
            } 
        }
        if(carry>0&&l1Stail->next==nullptr) l1Stail->next = new ListNode(carry);

        return head;
        


        
    }
};
